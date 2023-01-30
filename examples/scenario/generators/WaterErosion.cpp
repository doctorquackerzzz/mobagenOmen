//
// Created by docto on 1/23/2023.
//

#include "WaterErosion.h"
#include "RandomGenerator.h"
#include "../FastNoiseLite.h"
#include "../PerlinNoise.hpp"
#include <iostream>


std::vector<Color32> WaterErosion::Generate(int sideSize, float displacement)
{
  std::vector<Color32> colors;
  //   create your own function for noise generation
  FastNoiseLite base;
  base.SetFractalOctaves(3);
  base.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2S);
  base.SetFractalType(FastNoiseLite::FractalType_FBm);
  FastNoiseLite cellular;
  cellular.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
  cellular.SetFractalOctaves(3);

  std::vector<float> elevation;
  std::vector<float> island;

  for(int l=0; l<sideSize; l++){
    for(int c=0;c<sideSize; c++){
      float posX = (float)(l - sideSize/2) / (float)(sideSize/2);
      float posY = (float)(c - sideSize/2) / (float)(sideSize/2);
      float islandInfluence = 2 - abs(posX) + abs(posY);
      elevation.push_back((base.GetNoise((float)c, (float)l, displacement*50)+1)/2);
      //float c2 = ((cellular.GetNoise((float)c,(float)l, displacement*50) +1)/2) *255;

    }
  }
  for (auto e : elevation)
  {
    colors.push_back(Color32 (e, e, e));
  }
  std::cout<<colors.size() << std::endl;
  return colors;
}

std::string WaterErosion::GetName()
{
  return "Water Erosion";
}