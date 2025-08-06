#ifdef ENABLE_OPENMC_COUPLING

#include "OpenMCCellTranslation.h"
#include "openmc/capi.h"

registerMooseObject("CardinalApp", OpenMCCellTranslation);

InputParameters
OpenMCCellTranslation::validParams()
{
  auto params = OpenMCMaterialSearch::validParams();
  params.addClassDescription("Searches for criticality changing the position of one or more cells in units of m");
  return params;
}

OpenMCCellTranslation::OpenMCCellTranslation(const InputParameters & parameters)
  : OpenMCMaterialSearch(parameters)
{
  
}

void
OpenMCCellTranslation::updateOpenMCModel(const Real & translation)
{
  _console << "Searching for position = " << density << " [m] ..." << std::endl;



  int err = openmc_material_set_density(
      _material_index, density * _openmc_problem->densityConversionFactor(), units);
  catchOpenMCError(err, "set material density to " + std::to_string(density));
}

#endif
