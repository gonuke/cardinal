#pragma once

#include "CriticalitySearchBase.h"

/**
 * Perform a criticality search based on a material
 */
class OpenMCCellTransformSearch : public CriticalitySearchBase
{
public:
  static InputParameters validParams();

  OpenMCCellTransformSearch(const InputParameters & parameters);

protected:
  /// List of cell IDs to be transformed
  std::vector<int32_t> _cell_ids;

  /// Cell indices corresponding to the IDs
  std::vector<int32_t> _cell_indices;
};
