# test_bllsb.jl
# Simple code to test the Julia interface to BLLSB

using GALAHAD
using Printf

# Derived types
data = [Ptr{Ptr{Cvoid}}()]
control = bllsb_control_type{Float64}()
inform = bllsb_inform_type{Float64}()

# Set problem data
n = 3  # dimension
o = 4  # number of observations
Ao_ne = 7  # design matrix elements
Ao_row = Cint[1, 1, 2, 2, 3, 3, 4]  # row indices
Ao_col = Cint[1, 2, 2, 1, 3, 2]  # column indices
Ao_ptr_ne = o + 1 # row pointer length
Ao_ptr = Cint[1, 3, 5, 7, 8]  # row pointers
Ao_val = Float64[1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0]  # values
b = Float64[2.0, 2.0, 3.0, 1.0]  # observations
x_l = Float64[-1.0, -Inf, -Inf]  # variable lower bound
x_u = Float64[1.0, Inf, 2.0]  # variable upper bound
sigma = 1.0  # regularization weight
w = Float64[1.0, 1.0, 1.0, 2.0]  # values

# Set output storage
x_stat = zeros(Cint, n)  # variable status
st = ' '
status = Ref{Cint}()

@printf(" Fortran sparse matrix indexing\n\n")
@printf(" basic tests of bllsb storage formats\n\n")

for d = 1:3

  # Initialize BLLSB
  bllsb_initialize( data, control, status )

  # Set user-defined control options
  control.f_indexing = true  # Fortran sparse matrix indexing

  # Start from 0
  x = Float64[0.0,0.0,0.0]
  z = Float64[0.0,0.0,0.0]

  # sparse co-ordinate storage
  if d == 1
    global st = 'C'

    bllsb_import( control, data, status, n, o, 
                  "coordinate", Ao_ne, Ao_row, Ao_col, 0, Cint[] )

    bllsb_solve_bllsb( data, status, n, o, m, Ao_ne, Ao_val, b, sigma,
                       x_l, x_u, x, z, x_stat, w )
  end

  # sparse by rows
  if d == 2
    global st = 'R'

    bllsb_import( control, data, status, n, o,  
                 "sparse_by_rows", Ao_ne, Cint[], Ao_col, Ao_ptr_ne, Ao_ptr )


    bllsb_solve_bllsb( data, status, n, o, Ao_ne, Ao_val, b, sigma,
                       x_l, x_u, x, z, x_stat, w )
  end

  # dense
  if d == 3
    global st = 'D'

    Ao_dense_ne = 12  # number of elements of Ao
    Ao_dense = Float64[1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 
                       1.0, 0.0, 1.0, 0.0, 1.0, 0.0]

    bllsb_import( control, data, status, n, o, 
                  "dense", Ao_ne, Cint[], Cint[], 0, Cint[] )

    bllsb_solve_bllsb( data, status, n, o, Ao_dense_ne, Ao_dense, b, sigma,
                       x_l, x_u, x, z, x_stat, w )
  end

  bllsb_information( data, inform, status )

  if inform.status == 0
    @printf("%c:%6i iterations. Optimal objective value = %5.2f status = %1i\n", st, inform.iter, inform.obj, inform.status)
  else
    @printf("%c: BLLSB_solve exit status = %1i\n", st, inform.status)
  end

  # @printf("x: ")
  # for i = 1:n
  #   @printf("%f ", x[i])
  # end
  # @printf("\n")
  # @printf("gradient: ")
  # for i = 1:n
  #   @printf("%f ", g[i])
  # end
  # @printf("\n")

  # Delete internal workspace
  bllsb_terminate( data, control, inform )
end