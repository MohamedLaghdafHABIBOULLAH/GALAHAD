.. index:: pair: table; sha_control_type
.. _doxid-structsha__control__type:

sha_control_type structure
--------------------------

.. toctree::
	:hidden:

.. ref-code-block:: julia
	:class: doxyrest-overview-code-block

        struct sha_control_type
          f_indexing::Bool
          error::Int32
          out::Int32
          print_level::Int32
          approximation_algorithm::Int32
          dense_linear_solver::Int32
          max_sparse_degree::Int32
          extra_differences::Int32
          space_critical::Bool
          deallocate_error_fatal::Bool
          prefix::NTuple{31,Cchar}

.. _details-structsha__control__type:

detailed documentation
----------------------

control derived type as a Julia structure

components
~~~~~~~~~~

.. index:: pair: variable; f_indexing
.. _doxid-structsha__control__type_1a6e8421b34d6b85dcb33c1dd0179efbb3:

.. ref-code-block:: julia
	:class: doxyrest-title-code-block

	Bool f_indexing

use C or Fortran sparse matrix indexing

.. index:: pair: variable; error
.. _doxid-structsha__control__type_1a11614f44ef4d939bdd984953346a7572:

.. ref-code-block:: julia
	:class: doxyrest-title-code-block

	Int32 error

error and warning diagnostics occur on stream error

.. index:: pair: variable; out
.. _doxid-structsha__control__type_1aa8000eda101cade7c6c4b913fce0cc9c:

.. ref-code-block:: julia
	:class: doxyrest-title-code-block

	Int32 out

general output occurs on stream out

.. index:: pair: variable; print_level
.. _doxid-structsha__control__type_1a12dae630bd8f5d2d00f6a86d652f5c81:

.. ref-code-block:: julia
	:class: doxyrest-title-code-block

	Int32 print_level

the level of output required. <= 0 gives no output, = 1 gives a one-line summary for every iteration, = 2 gives a summary of the inner iteration for each iteration, >= 3 gives increasingly verbose (debugging) output

.. index:: pair: variable; approximation_algorithm
.. _doxid-structsha__control__type_1af04b00dd3ef8468bec194d10ee43f8b7:

.. ref-code-block:: julia
	:class: doxyrest-title-code-block

	Int32 approximation_algorithm

which approximation algorithm should be used?

* 0 : unsymmetric (alg 2.1 in paper)

* 1 : symmetric (alg 2.2 in paper)

* 2 : composite (alg 2.3 in paper)

* 3 : composite 2 (alg 2.2/3 in paper)

.. index:: pair: variable; dense_linear_solver
.. _doxid-structsha__control__type_1a59b9cb51e0d19a10a7714b4582a883b1:

.. ref-code-block:: julia
	:class: doxyrest-title-code-block

	Int32 dense_linear_solver

which dense linear equation solver should be used?

* 1 : Gaussian elimination

* 2 : QR factorization

* 3 : singular-value decomposition

* 4 : singular-value decomposition with divide-and-conquer

.. index:: pair: variable; max_sparse_degree
.. _doxid-structsha__control__type_1a22a3fbc66d8826eb54a1708046e3c4f0:

.. ref-code-block:: julia
	:class: doxyrest-title-code-block

	Int32 max_sparse_degree

the maximum sparse degree if the combined version is used

.. index:: pair: variable; extra_differences
.. _doxid-structsha__control__type_1a16e4be90c05808f00af594b1feabadbe:

.. ref-code-block:: julia
	:class: doxyrest-title-code-block

	Int32 extra_differences

if available use an addition extra_differences differences

.. index:: pair: variable; space_critical
.. _doxid-structsha__control__type_1a957fc1f4f26eeef3b0951791ff972e8d:

.. ref-code-block:: julia
	:class: doxyrest-title-code-block

	Bool space_critical

if space is critical, ensure allocated arrays are no bigger than needed

.. index:: pair: variable; deallocate_error_fatal
.. _doxid-structsha__control__type_1a58a2c67fad6e808e8365eff67700cba5:

.. ref-code-block:: julia
	:class: doxyrest-title-code-block

	Bool deallocate_error_fatal

exit if any deallocation fails

.. index:: pair: variable; prefix
.. _doxid-structsha__control__type_1a1dc05936393ba705f516a0c275df4ffc:

.. ref-code-block:: julia
	:class: doxyrest-title-code-block

	NTuple{31,Cchar} prefix

all output lines will be prefixed by .prefix(2:LEN(TRIM(.prefix))-1) where .prefix contains the required string enclosed in quotes, e.g. "string" or 'string'

