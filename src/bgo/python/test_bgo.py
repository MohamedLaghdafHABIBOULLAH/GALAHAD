from galahad import bgo
import numpy as np

# allocate internal data and set default options
bgo.initialize()

# set some non-default options
options = {'print_level' : 3, 'ugo_options' : {'print_level' : 4}}
print(options)

# set parameters
p = 4
freq = 10
mag = 1000
# set bounds
n = 3
x_l = np.array([-10.0,-10.0,-10.0])
x_u = np.array([0.5,0.5,0.5])

# set Hessian sparsity
H_type = 'coordinate'
ne = 5
H_row = np.array([0,1,2,2,2])
H_col = np.array([0,1,0,1,2])
H_ptr = None

# load data (and optionally non-default options)
bgo.load(n, x_l, x_u, H_type, ne, H_row, H_col, H_ptr, options=options)

# define objective function
# NB python functions have access to external variables
# So no need for userdata like in C or Fortran
def eval_f(x):
    return (x[0] + x[2] + p)**2 + (x[1] + x[2])**2 + mag * np.cos(freq * x[0]) + x[0] + x[1] + x[2]
def eval_g(x):
    return np.array([2. * ( x[0] + x[2] + p ) 
                     - mag * freq * np.sin(freq * x[0]) + 1.,
                     2. * ( x[1] + x[2] ) + 1.,
                     2. * ( x[0] + x[2] + p ) + 2.0 * ( x[1] + x[2] ) + 1.])
def eval_h(x):
    return np.array([2. - mag * freq * freq * np.cos(freq * x[0]),2.,2.,2.,2.])

def eval_hprod(x,u,v):
    return np.array([u[0] + 2. * ( v[0] + v[2] ) 
                     - mag * freq * freq * np.cos(freq * x[0]) * v[0],
                     u[1] + 2. * ( v[1] + v[2]),
                     u[2] + 2. * ( v[0] + v[1] + 2. * v[2] )])

# set starting point

x = np.array([0.,0.,0.])

# starting gradient
g = eval_g(x)

# find optimum
x, g = bgo.solve(n, x, g, eval_f, eval_g, eval_h, eval_hprod)
print("x:",x)
print("g:",g)

# get information
inform = bgo.information()
#print(inform)
print("f:",inform['obj'])

# deallocate internal data
bgo.terminate()