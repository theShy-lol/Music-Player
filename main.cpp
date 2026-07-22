#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include"Playlist.h"
//Audio player
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio/miniaudio.h"



int main()

{
    ma_result result;
    ma_engine engine;
    ma_sound song;
    bool isTrackPlaying;
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return -1;
    }

    std::cout<<"===Welcome to the best music Player(maybe not)==="<<std::endl;
    std::cout<<"   Chose a song mate!  "<<std::endl;

    int choice;

    for(int i = 0; i < Playlist.size(); i++){
        std::cout<<i + 1<<"."<<Playlist[i]<<std::endl;
    }
    std::cin>>choice;

    if(isTrackPlaying){
        ma_sound_uninit(&song);
        isTrackPlaying = false;
    }

    ma_result start = ma_sound_init_from_file(
    &engine, 
    Playlist[choice - 1].c_str(), 
    0, 
    NULL, 
    NULL, 
    &song
    );
    if(start == MA_SUCCESS){
        ma_sound_start(&song);
        isTrackPlaying = true;
    }
    else{
        std::cout<<"Failed to load"<<std::endl;
    }
    std::cin.ignore(1);
    
    //Controls
    int option;
    std::cout<<"===Controls:  "<<std::endl;
    while(option != 5){
        std::cout<<"1. Next"<<std::endl;
        std::cout<<"2. Previous"<<std::endl;
        std::cout<<"3. Pause"<<std::endl;
        std::cout<<"4. Resume"<<std::endl;
        std::cout<<"5. Anything else.. quit"<<std::endl;
        std::cin>>option;
        if(option == 1){
            if(isTrackPlaying){
                ma_sound_uninit(&song);
                choice++;
                ma_sound_init_from_file(
                &engine, 
                Playlist[choice - 1].c_str(), 
                0, 
                NULL, 
                NULL, 
                &song
                );
                ma_sound_start(&song);
            }
        }
        else if(option == 2){
            if(isTrackPlaying){
                ma_sound_uninit(&song);
                if(choice != 1){
                    choice--;
                    ma_sound_init_from_file(
                    &engine, 
                    Playlist[choice - 1].c_str(), 
                    0, 
                    NULL, 
                    NULL, 
                    &song
                    );
                    ma_sound_start(&song);
                }
                else{
                    ma_sound_init_from_file(
                    &engine, 
                    Playlist[Playlist.size() - 1].c_str(), 
                    0, 
                    NULL, 
                    NULL, 
                    &song
                    );
                    ma_sound_start(&song);
                }
            }
        }
        else if(option == 3){
            ma_sound_uninit(&song);
            isTrackPlaying = false;
        }
        else if(option == 4){
            if(!isTrackPlaying){
            ma_sound_init_from_file(
            &engine, 
            Playlist[choice - 1].c_str(), 
            0, 
            NULL, 
            NULL, 
            &song
            );
            ma_sound_start(&song);
            }
            isTrackPlaying = true;
        }
        else{
            ma_engine_uninit(&engine);
        }
        system("cls");
    }
    getchar();

    ma_engine_uninit(&engine);

    return 0;
}