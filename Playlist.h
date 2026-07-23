#include<vector>
#include<iostream>
#include<string>

std::vector<std::string> Playlist = {
        "Songs/Project X.mp3", "Songs/Funk insta #1.mp3",
        "Songs/Ichika beat.mp3", "Songs/Cand Oceanele.mp3", "Songs/fgbndgjdgjhdghndgnsfgnsfgbfbadfhadfg.mp3"

};

std::string trim(std::string current_song){                    
        std::string noHead = current_song.substr(6);
        std::string full = noHead.substr(0,noHead.find('.'));
        return full;

}