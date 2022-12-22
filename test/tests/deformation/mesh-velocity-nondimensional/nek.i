[Mesh]
  type = NekRSMesh
  order = SECOND
  boundary = '2'
  parallel_type = replicated
  displacements = 'disp_x disp_y disp_z'
  scaling = 1.0
[]

[Problem]
  type = NekRSProblem
  casename = 'pipe'
  synchronization_interval = parent_app

  nondimensional = true
  U_ref = 100
  T_ref = 1.0
  dT_ref = 1.0
  L_ref = 1.0
  rho_0 = 1.0
  Cp_0 = 1.0
[]

[AuxVariables]
  [dummy]
  []
[]

# This AuxVariable and AuxKernel is only here to get the postprocessors
# to evaluate correctly. This can be deleted after MOOSE issue #17534 is fixed.
[AuxKernels]
  [dummy]
    type = ConstantAux
    variable = dummy
    value = 0.0
  []
[]

[Executioner]
  type = Transient
  [TimeStepper]
    type = NekTimeStepper
  []
  [Quadrature]
    type = GAUSS_LOBATTO
    order = SECOND
  []
[]

[Postprocessors]
  [nekbdry_icar]
    type = NekSideIntegral
    field = unity
    boundary = '2'
    use_displaced_mesh = true
    execute_on = INITIAL
  []
  [nekbdry_ar]
    type = NekSideIntegral
    field = unity
    boundary = '2'
    use_displaced_mesh = true
  []
[]

[Outputs]
  csv = true
  execute_on = 'final'
  hide = 'flux_integral'
[]
