template <typename Resource, typename Identifier>
void TextureHolder<Resource, Identifier>::load(Identifier id, const std::string &filename)
{
    std::unique_ptr<Texture> texture(new Texture());
    if (!texture->loadFromFile(filename))
        throw std::runtime_error("TextureHolder::load - failed to load " + filename);

    //insert the resource
    mTextureMap.insert(std::make_pair(id, std::move(texture)));
}

template <typename Resource, typename Identifier>
Texture &TextureHolder<Resource, Identifier>::get(Identifier id)
{
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());

    return *found->second;
}

template <typename Resource, typename Identifier>
Texture &TextureHolder<Resource, Identifier>::get(Identifier id) const
{
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());

    return *found->second;
}