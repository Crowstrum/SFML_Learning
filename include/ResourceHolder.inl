template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string &filename)
{
    std::unique_ptr<Texture> texture(new Texture());
    if (!texture->loadFromFile(filename))
        throw std::runtime_error("ResourceHolder::load - failed to load " + filename);

    //insert the resource
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted->second);
}
template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string &filename, const Parameter &secondParam)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource.loadFromFile(filename, secondParam))
    {
        throw std::runtime_error("ResourceHolder::load(shader overload) - failed to load" + filename);
    }

    auto insterted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(insterted->second);
}

template <typename Resource, typename Identifier>
Texture &ResourceHolder<Resource, Identifier>::get(Identifier id)
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());

    return *found->second;
}

template <typename Resource, typename Identifier>
Texture &ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());

    return *found->second;
}