//
// Created by docto on 1/23/2023.
//

#ifndef MOBAGENOMEN_WATEREROSION_H
#define MOBAGENOMEN_WATEREROSION_H
#include "../GeneratorBase.h"

class WaterErosion : public ScenarioGeneratorBase{
 public:
  std::vector<Color32> Generate(int sideSize, float displacement=0) override;
  std::string GetName() override;
};

#endif  // MOBAGENOMEN_WATEREROSION_H
