#include <vector>
#include <string>
#include "Wallpaper.h"
#include "WallpaperParser.h"
#include <boost/random.hpp>




class WallpaperManager
{
private:
    std::string _path;
public:
    std::vector<std::tuple<type, std::string>> fullWallpapersList;
    std::vector<std::string> videoWallpapersList;
    std::vector<std::string> photoWallpapersList;
    WallpaperManager(std::string path);

    std::vector<std::string> getVideoWallpapers();
    std::vector<std::string> getPhotoWallpapers();
    std::string getRandomWallpaper(std::vector<std::string>);
    void SetRandomWallpaper(type);
};

