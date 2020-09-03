#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <SFML/graphics.hpp>
#include <map>

template <typename Resource, typename Identifier>
class ResourceHolder
{
private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;

public:
    void load(Identifier id, const std::string &filename);
    template <typename Parameter>
    void load(Identifier id, const std::string &filename, const Parameter &secondParam);
    sf::Texture &get(Identifier id);
    sf::Texture &get(Identifier id) const;
};

#include "ResourceHolder.inl"
#endif