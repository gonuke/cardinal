#ifdef ENABLE_OPENMC_COUPLING

#include "OpenMCTranslateSurface.h"
#include "openmc/surface.h"

registerMooseObject("CardinalApp", OpenMCTranslateSurface);

InputParameters
OpenMCTranslateSurface::validParams()
{
  InputParameters params = GeneralUserObject::validParams();
  params += OpenMCBase::validParams();
  params.addRequiredParam<int32_t>("surface_id", "ID of surface to change position");
  params.addRequiredParam<double>("displacement", "Change in location of surface (cm)");
  params.declareControllable("displacement");
  params.addClassDescription("Displaces a surface in an OpenMC geometry.");
  return params;
}

OpenMCTranslateSurface::OpenMCTranslateSurface(const InputParameters & parameters)
  : GeneralUserObject(parameters),
    OpenMCBase(this, parameters),
    _surface_id(getParam<int32_t>("surface_id")),
    _displacement(getParam<double>("displacement"))
{
  // probably not correct
  _openmc_problem->catchOpenMCError(_surface_index = openmc::model::surface_map[_surface_id], 
                                    "get the surface index for surface with ID " +
                                    std::to_string(_surface_id));
}

void
OpenMCTranslateSurface::setValue()
{
  try
  {
    openmc::model::surfaces[_surface_index]->set_densities(_names, _displacement);
  }
  catch (const std::exception & e)
  {
    mooseError("In attempting to set nuclide densities in the '" + name() +
               "' UserObject, OpenMC reported:\n\n" + e.what());
  }
}

#endif
