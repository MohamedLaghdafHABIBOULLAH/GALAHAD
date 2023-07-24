export gltr_control_type

mutable struct gltr_control_type{T}
  f_indexing::Bool
  error::Cint
  out::Cint
  print_level::Cint
  itmax::Cint
  Lanczos_itmax::Cint
  extra_vectors::Cint
  ritz_printout_device::Cint
  stop_relative::T
  stop_absolute::T
  fraction_opt::T
  f_min::T
  rminvr_zero::T
  f_0::T
  unitm::Bool
  steihaug_toint::Bool
  boundary::Bool
  equality_problem::Bool
  space_critical::Bool
  deallocate_error_fatal::Bool
  print_ritz_values::Bool
  ritz_file_name::NTuple{31,Cchar}
  prefix::NTuple{31,Cchar}

  gltr_control_type{T}() where T = new()
end

export gltr_inform_type

mutable struct gltr_inform_type{T}
  status::Cint
  alloc_status::Cint
  bad_alloc::NTuple{81,Cchar}
  iter::Cint
  iter_pass2::Cint
  obj::T
  multiplier::T
  mnormx::T
  piv::T
  curv::T
  rayleigh::T
  leftmost::T
  negative_curvature::Bool
  hard_case::Bool

  gltr_inform_type{T}() where T = new()
end

export gltr_initialize_s

function gltr_initialize_s(data, control, status)
  @ccall libgalahad_single.gltr_initialize_s(data::Ptr{Ptr{Cvoid}},
                                             control::Ref{gltr_control_type{Float32}},
                                             status::Ptr{Cint})::Cvoid
end

export gltr_initialize

function gltr_initialize(data, control, status)
  @ccall libgalahad_double.gltr_initialize(data::Ptr{Ptr{Cvoid}},
                                           control::Ref{gltr_control_type{Float64}},
                                           status::Ptr{Cint})::Cvoid
end

export gltr_read_specfile_s

function gltr_read_specfile_s(control, specfile)
  @ccall libgalahad_single.gltr_read_specfile_s(control::Ref{gltr_control_type{Float32}},
                                                specfile::Ptr{Cchar})::Cvoid
end

export gltr_read_specfile

function gltr_read_specfile(control, specfile)
  @ccall libgalahad_double.gltr_read_specfile(control::Ref{gltr_control_type{Float64}},
                                              specfile::Ptr{Cchar})::Cvoid
end

export gltr_import_control_s

function gltr_import_control_s(control, data, status)
  @ccall libgalahad_single.gltr_import_control_s(control::Ref{gltr_control_type{Float32}},
                                                 data::Ptr{Ptr{Cvoid}},
                                                 status::Ptr{Cint})::Cvoid
end

export gltr_import_control

function gltr_import_control(control, data, status)
  @ccall libgalahad_double.gltr_import_control(control::Ref{gltr_control_type{Float64}},
                                               data::Ptr{Ptr{Cvoid}},
                                               status::Ptr{Cint})::Cvoid
end

export gltr_solve_problem_s

function gltr_solve_problem_s(data, status, n, radius, x, r, vector)
  @ccall libgalahad_single.gltr_solve_problem_s(data::Ptr{Ptr{Cvoid}}, status::Ptr{Cint},
                                                n::Cint, radius::Float32, x::Ptr{Float32},
                                                r::Ptr{Float32},
                                                vector::Ptr{Float32})::Cvoid
end

export gltr_solve_problem

function gltr_solve_problem(data, status, n, radius, x, r, vector)
  @ccall libgalahad_double.gltr_solve_problem(data::Ptr{Ptr{Cvoid}}, status::Ptr{Cint},
                                              n::Cint, radius::Float64, x::Ptr{Float64},
                                              r::Ptr{Float64},
                                              vector::Ptr{Float64})::Cvoid
end

export gltr_information_s

function gltr_information_s(data, inform, status)
  @ccall libgalahad_single.gltr_information_s(data::Ptr{Ptr{Cvoid}},
                                              inform::Ref{gltr_inform_type{Float32}},
                                              status::Ptr{Cint})::Cvoid
end

export gltr_information

function gltr_information(data, inform, status)
  @ccall libgalahad_double.gltr_information(data::Ptr{Ptr{Cvoid}},
                                            inform::Ref{gltr_inform_type{Float64}},
                                            status::Ptr{Cint})::Cvoid
end

export gltr_terminate_s

function gltr_terminate_s(data, control, inform)
  @ccall libgalahad_single.gltr_terminate_s(data::Ptr{Ptr{Cvoid}},
                                            control::Ref{gltr_control_type{Float32}},
                                            inform::Ref{gltr_inform_type{Float32}})::Cvoid
end

export gltr_terminate

function gltr_terminate(data, control, inform)
  @ccall libgalahad_double.gltr_terminate(data::Ptr{Ptr{Cvoid}},
                                          control::Ref{gltr_control_type{Float64}},
                                          inform::Ref{gltr_inform_type{Float64}})::Cvoid
end
