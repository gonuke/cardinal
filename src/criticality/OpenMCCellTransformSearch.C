#ifdef ENABLE_OPENMC_COUPLING

#include "OpenMCCellTransformSearch.h"
#include "UserErrorChecking.h"
#include "openmc/capi.h"

InputParameters
OpenMCCellTransformSearch::validParams()
{
  auto params = CriticalitySearchBase::validParams();
  params.addRequiredParam<std::vector<int32_t>>("cell_ids", "Cell IDs to modify");
  params.addClassDescription(
      "Base class for criticality searches using the location of one or more cells");
  return params;
}

OpenMCCellTransformSearch::OpenMCCellTransformSearch(const InputParameters & parameters)
  : CriticalitySearchBase(parameters), _cell_ids(getParam<std::vector<int32_t>>("cell_ids"))
  {

    for (const auto & cell_id : _cell_ids) 
    {
      int err = // get cell_index openmc_get_material_index(_material_id, &_material_index);
      catchOpenMCError(err, "get index for cell with ID " + std::to_string(cell_id));

      _cell_indices.push_back(cell_index)
    }    

  }
  
#endif
