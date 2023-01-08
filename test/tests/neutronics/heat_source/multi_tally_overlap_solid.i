[Mesh]
  [sphere]
    type = FileMeshGenerator
    file = ../meshes/sphere.e
  []
  [solid]
    type = CombinerGenerator
    inputs = sphere
    positions = '0 0 0
                 0 0 4
                 0 0 8'
  []
  [solid_ids]
    type = SubdomainIDGenerator
    input = solid
    subdomain_id = '100'
  []
  [fluid]
    type = FileMeshGenerator
    file = stoplight.exo
  []
  [fluid_ids]
    type = SubdomainIDGenerator
    input = fluid
    subdomain_id = '200'
  []
  [combine]
    type = CombinerGenerator
    inputs = 'solid_ids fluid_ids'
  []
[]

# This AuxVariable and AuxKernel is only here to get the postprocessors
# to evaluate correctly. This can be deleted after MOOSE issue #17534 is fixed.
[AuxVariables]
  [dummy]
  []
[]

[AuxKernels]
  [dummy]
    type = ConstantAux
    variable = dummy
    value = 0.0
  []
[]

[Problem]
  type = OpenMCCellAverageProblem
  power = 100.0
  solid_blocks = '100'
  fluid_blocks = '200'
  tally_blocks = '100'
  verbose = true
  solid_cell_level = 0
  fluid_cell_level = 0
  tally_type = cell
  normalize_by_global_tally = false
  check_tally_sum = false

  tally_score = 'kappa_fission heating'

  initial_properties = xml
[]

[Executioner]
  type = Transient
  num_steps = 1
[]

[Postprocessors]
  [kappa_fission]
    type = ElementIntegralVariablePostprocessor
    variable = kappa_fission
  []
  [fluid_kappa_fission]
    type = ElementIntegralVariablePostprocessor
    variable = kappa_fission
    block = '200'
  []
  [solid_kappa_fission]
    type = ElementIntegralVariablePostprocessor
    variable = kappa_fission
    block = '100'
  []
  [heating]
    type = ElementIntegralVariablePostprocessor
    variable = heating
  []
  [fluid_heating]
    type = ElementIntegralVariablePostprocessor
    variable = heating
    block = '200'
  []
  [solid_heating]
    type = ElementIntegralVariablePostprocessor
    variable = heating
    block = '100'
  []
[]

[Outputs]
  csv = true
[]