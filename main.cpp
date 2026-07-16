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
    std::cout<<"   Chose a song mate!  "<<std::endl;
    int choice;
    
    for(int i = 0; i < Playlist.size(); i++){
        std::cout<<i + 1<<"."<<Playlist[i]<<std::endl;
        
    }
    std::cin>>choice;
    switch (choice){
        case 1:
            ma_engine_play_sound(&engine, Playlist[0].c_str(), NULL);
            break;
        case 2:
            ma_engine_play_sound(&engine, Playlist[1].c_str(), NULL);
            break;
        case 3:
            ma_engine_play_sound(&engine, Playlist[2].c_str(), NULL);
            break;
        }
    
    std::cin.ignore(1);

    std::cout<<"Press Enter to quit...";
    getchar();

    ma_engine_uninit(&engine);

    return 0;
}