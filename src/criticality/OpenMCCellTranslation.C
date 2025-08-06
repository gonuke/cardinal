#ifdef ENABLE_OPENMC_COUPLING

#include "OpenMCCellTranslation.h"
#include "openmc/capi.h"

registerMooseObject("CardinalApp", OpenMCCellTranslation);

InputParameters
OpenMCCellTranslation::validParams()
{
  auto params = OpenMCMaterialSearch::validParams();
  params.addRequiredParam<std::vector<double>>("direction", "Unit vector definiting direction  of translation (will be normalized)");
  params.addClassDescription("Searches for criticality changing the position of one or more cells in units of m");
  return params;
}

OpenMCCellTranslation::OpenMCCellTranslation(const InputParameters & parameters)
  : OpenMCMaterialSearch(parameters), _dir(getParam<std::vector<double>>("direction"))
{
  
  // TODO?: some check to make sure it makes sense to move each cell in this way

  // TODO?: some check to make sure it makes sense to move all the cells in the same way

}

void
OpenMCCellTranslation::updateOpenMCModel(const Real & translation)
{
  _console << "Searching for position = " << translation << " [m] in direction " 
          << std::to_string(_dir) << " ..." << std::endl;

  for (const auto & cell_index : _cell_indices){

    int err = 0; // set OpenMC cell translation
    catchOpenMCError(err, "set cell translation " + std::to_string(translation));
  
  }

  


}


#endif
