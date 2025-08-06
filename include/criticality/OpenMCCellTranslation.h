#pragma once

#include "OpenMCCellTransformSearch.h"

/**
 * Perform a criticality search based on a material total density
 */
class OpenMCCellTranslation : public OpenMCCellTransformSearch
{
public:
  static InputParameters validParams();

  OpenMCCellTranslation(const InputParameters & parameters);

  virtual void updateOpenMCModel(const Real & input) override;

protected:
  virtual std::string quantity() const override
  {
    std::string message = "position of cells ";
    for (const auto & cell_id : _cell_ids )
    {
        message += std::to_string(cell_id) + ", ";
    }
    return message;
  }

  virtual std::string units() const override { return "[m]"; }
};
