#include "WallpaperManager.h"

WallpaperManager::WallpaperManager(std::string path)
{
    this->_path = path;
    WallpaperParser parser(path);
    fullWallpapersList = parser.ParseFromFolder();
}

std::vector<std::string> WallpaperManager::getVideoWallpapers()
{
    for (auto x : fullWallpapersList)
    {
        if (std::get<0>(x) == type::video) {
            videoWallpapersList.push_back(std::get<1>(x));
        }
    }
    return videoWallpapersList;
}

std::vector<std::string> WallpaperManager::getPhotoWallpapers()
{
    for (auto x : fullWallpapersList)
    {
        if (std::get<0>(x) == type::photo) {
            photoWallpapersList.push_back(std::get<1>(x));
        }
    }
    return photoWallpapersList;
}

std::string WallpaperManager::getRandomWallpaper(std::vector<std::string> wallpapers)
{
    std::time_t now = std::time(0);
    boost::random::mt19937 gen{static_cast<std::uint32_t>(now)};
    boost::random::uniform_int_distribution<> dist{0, (int)wallpapers.size() - 1};
    return wallpapers[dist(gen)];
}

void WallpaperManager::SetRandomWallpaper(type wType)
{
    std::string finalString;
    switch (wType)
    {
    case type::video:
        finalString = "./setup.sh -nb " + _path + '/' + getRandomWallpaper(getVideoWallpapers());
        system(finalString.c_str());
        break;
    case type::photo:
        finalString = "/usr/bin/feh --bg-scale " + _path + '/' + getRandomWallpaper(getPhotoWallpapers());
        system(finalString.c_str());
        break;
    }
}

