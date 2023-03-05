#include <iostream>
#include <map>
#include "WallpaperManager.h"

int main(int argc, char *argv[])
{
    WallpaperManager Manager(argv[1]);
    Manager.SetRandomWallpaper(type::video);
}