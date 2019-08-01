//
// Created by robin on 01.08.2019.
//

#include "Layer.h"

tson::Layer::Layer(const nlohmann::json &json)
{
    parse(json);
}

bool tson::Layer::parse(const nlohmann::json &json)
{
    bool allFound = true;
    if(json.count("compression") > 0) m_compression = json["compression"].get<std::string>(); //Optional
    if(json.count("draworder") > 0) m_drawOrder = json["draworder"].get<std::string>(); //Optional
    if(json.count("encoding") > 0) m_encoding = json["encoding"].get<std::string>(); //Optional
    if(json.count("id") > 0) m_id = json["id"].get<int>(); //Optional
    if(json.count("image") > 0) m_image = json["image"].get<std::string>(); //Optional
    if(json.count("name") > 0) m_name = json["name"].get<std::string>(); else allFound = false;
    if(json.count("offsetx") > 0 && json.count("offsety") > 0)
        m_offset = {json["offsetx"].get<float>(), json["offsety"].get<float>()}; //Optional
    if(json.count("opacity") > 0) m_opacity = json["opacity"].get<float>(); else allFound = false;
    if(json.count("width") > 0 && json.count("height") > 0)
        m_size = {json["width"].get<int>(), json["height"].get<int>()}; else allFound = false;
    if(json.count("transparentcolor") > 0) m_transparentcolor = tson::Color(json["transparentcolor"].get<std::string>()); //Optional
    if(json.count("type") > 0) m_type = json["type"].get<std::string>(); else allFound = false;
    if(json.count("visible") > 0) m_visible = json["visible"].get<bool>(); else allFound = false;
    if(json.count("x") > 0) m_x = json["x"].get<int>(); else allFound = false;
    if(json.count("y") > 0) m_y = json["y"].get<int>(); else allFound = false;

    //Handle DATA
    if(json.count("data") > 0)
    {
        if(json["data"].is_array())
        {
            std::for_each(json["data"].begin(), json["data"].end(), [&](const nlohmann::json &item) { m_data.push_back(item.get<int>()); });
        }
        else
            m_base64Data = json["data"].get<std::string>();
    }
    else
        allFound = false;

    return allFound;
}

const std::string &tson::Layer::getCompression() const
{
    return m_compression;
}

const std::vector<int> &tson::Layer::getData() const
{
    return m_data;
}

const std::string &tson::Layer::getBase64Data() const
{
    return m_base64Data;
}

const std::string &tson::Layer::getDrawOrder() const
{
    return m_drawOrder;
}

const std::string &tson::Layer::getEncoding() const
{
    return m_encoding;
}

int tson::Layer::getId() const
{
    return m_id;
}

const std::string &tson::Layer::getImage() const
{
    return m_image;
}

const std::string &tson::Layer::getName() const
{
    return m_name;
}

const tson::Vector2f &tson::Layer::getOffset() const
{
    return m_offset;
}

float tson::Layer::getOpacity() const
{
    return m_opacity;
}

const tson::Vector2i &tson::Layer::getSize() const
{
    return m_size;
}

const tson::Color &tson::Layer::getTransparentcolor() const
{
    return m_transparentcolor;
}

const std::string &tson::Layer::getType() const
{
    return m_type;
}

bool tson::Layer::isVisible() const
{
    return m_visible;
}

int tson::Layer::getX() const
{
    return m_x;
}

int tson::Layer::getY() const
{
    return m_y;
}
