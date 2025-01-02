#pragma once

#include "raylib.h"
#include <map>
#include <string>

class SoundManager {
public:
    static SoundManager& GetInstance() {
        static SoundManager instance;
        return instance;
    }

    // Loads all game sounds
    void LoadSounds() {
        sounds["block_hit"] = LoadSound("blockHit.wav");
        sounds["border_hit"] = LoadSound("borderHit.wav");

        SetMasterVolume(GetMasterVolume() / 4);
    }

    // Get a sound that matches the name
    Sound& GetSound(const std::string& name) {
        return sounds[name]; 
    }

    // Unload all sounds from memory and clear the sound map
    void UnloadSounds() {
        for (auto& sound : sounds) {
            UnloadSound(sound.second);
        }
        sounds.clear();
    }

private:
    SoundManager() {}
    std::map<std::string, Sound> sounds;
};
