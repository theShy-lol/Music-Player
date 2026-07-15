#include<iostream>
#include<string>
#include<vector>
//Audio player
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio/miniaudio.h"
int main()
{
    ma_result result;
    ma_engine engine;

    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return -1;
    }
    std::vector<std::string> Playlist = {
        "Project X.mp3", "Funk insta #1.mp3",
        "Ichika beat.mp3"
    };
    std::cout<<"===Welcome to the best music Player(maybe not)==="<<std::endl;

    for(int i = 0; i < Playlist.size(); i++){
        std::cout<<"Chose a song mate!"<<std::endl;
        std::cout<<Playlist[i]<<std::endl;
    }
    
    ma_engine_play_sound(&engine, "Project X.mp3", NULL);

    printf("Press Enter to quit...");
    getchar();

    ma_engine_uninit(&engine);

    return 0;
}