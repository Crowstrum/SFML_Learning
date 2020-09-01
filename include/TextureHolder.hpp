#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <SFML/graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

template <typename Resource, typename Identifier>
class TextureHolder
{
private:
    map<Identifier, unique_ptr<Resource>> mTextureMap;

public:
    void load(Identifier id, const string &filename);
    Texture &get(Identifier id);
    Texture &get(Identifier id) const;
};

#include "TextureHolder.inl"
#endif