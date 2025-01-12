.. index:: pair: struct; gls_ainfo
.. _doxid-structgls__ainfo:

gls_ainfo structure
-------------------

.. toctree::
	:hidden:

.. ref-code-block:: cpp
	:class: doxyrest-overview-code-block

	#include <galahad_gls.h>
	
	struct gls_ainfo {
		// fields
	
		int :ref:`flag<doxid-structgls__ainfo_1adf916204820072417ed73a32de1cefcf>`;
		int :ref:`more<doxid-structgls__ainfo_1a4628f2fb17af64608416810cc4e5a9d0>`;
		int :ref:`len_analyse<doxid-structgls__ainfo_1aa0296ccd8aa2c86d573fc176876ad1b3>`;
		int :ref:`len_factorize<doxid-structgls__ainfo_1a41ce64037dc7aae66b5a4ac582a2985a>`;
		int :ref:`ncmpa<doxid-structgls__ainfo_1a5e8b1d7aba05cfece368396811da24a3>`;
		int :ref:`rank<doxid-structgls__ainfo_1a6cfd95afd0afebd625b889fb6e58371c>`;
		int :ref:`drop<doxid-structgls__ainfo_1a56da9169fe581b834e971dee4997ecfd>`;
		int :ref:`struc_rank<doxid-structgls__ainfo_1adb25a546fdb408d29ea28385fe414361>`;
		int :ref:`oor<doxid-structgls__ainfo_1afa0283d540a2a393c746b5eb05c3431c>`;
		int :ref:`dup<doxid-structgls__ainfo_1adc4cf3f551bb367858644559d69cfdf5>`;
		int :ref:`stat<doxid-structgls__ainfo_1a7d6f8a25e94209bd3ba29b2051ca4f08>`;
		int :ref:`lblock<doxid-structgls__ainfo_1a1e1f13a9a57bbd9e84303bdc2b49b2fc>`;
		int :ref:`sblock<doxid-structgls__ainfo_1ad319083836152d74198f05040820282b>`;
		int :ref:`tblock<doxid-structgls__ainfo_1aed4a0eb964f83e8a0a29ae1f2e0f5cce>`;
		:ref:`real_wp_<doxid-galahad__precision_8h_1ab82133d435678ff159433d2e50cf295e>` :ref:`ops<doxid-structgls__ainfo_1af0a337c9f4d03e088123ec071639aad7>`;
	};
.. _details-structgls__ainfo:

detailed documentation
----------------------

ainfo derived type as a C struct

components
~~~~~~~~~~

.. index:: pair: variable; flag
.. _doxid-structgls__ainfo_1adf916204820072417ed73a32de1cefcf:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int flag

Flags success or failure case.

.. index:: pair: variable; more
.. _doxid-structgls__ainfo_1a4628f2fb17af64608416810cc4e5a9d0:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int more

More information on failure.

.. index:: pair: variable; len_analyse
.. _doxid-structgls__ainfo_1aa0296ccd8aa2c86d573fc176876ad1b3:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int len_analyse

Size for analysis.

.. index:: pair: variable; len_factorize
.. _doxid-structgls__ainfo_1a41ce64037dc7aae66b5a4ac582a2985a:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int len_factorize

Size for factorize.

.. index:: pair: variable; ncmpa
.. _doxid-structgls__ainfo_1a5e8b1d7aba05cfece368396811da24a3:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int ncmpa

Number of compresses.

.. index:: pair: variable; rank
.. _doxid-structgls__ainfo_1a6cfd95afd0afebd625b889fb6e58371c:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int rank

Estimated rank.

.. index:: pair: variable; drop
.. _doxid-structgls__ainfo_1a56da9169fe581b834e971dee4997ecfd:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int drop

Number of entries dropped.

.. index:: pair: variable; struc_rank
.. _doxid-structgls__ainfo_1adb25a546fdb408d29ea28385fe414361:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int struc_rank

Structural rank of matrix.

.. index:: pair: variable; oor
.. _doxid-structgls__ainfo_1afa0283d540a2a393c746b5eb05c3431c:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int oor

Number of indices out-of-range.

.. index:: pair: variable; dup
.. _doxid-structgls__ainfo_1adc4cf3f551bb367858644559d69cfdf5:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int dup

Number of duplicates.

.. index:: pair: variable; stat
.. _doxid-structgls__ainfo_1a7d6f8a25e94209bd3ba29b2051ca4f08:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int stat

STAT value after allocate failure.

.. index:: pair: variable; lblock
.. _doxid-structgls__ainfo_1a1e1f13a9a57bbd9e84303bdc2b49b2fc:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int lblock

Size largest non-triangular block.

.. index:: pair: variable; sblock
.. _doxid-structgls__ainfo_1ad319083836152d74198f05040820282b:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int sblock

Sum of orders of non-triangular blocks.

.. index:: pair: variable; tblock
.. _doxid-structgls__ainfo_1aed4a0eb964f83e8a0a29ae1f2e0f5cce:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int tblock

Total entries in all non-tringular blocks.

.. index:: pair: variable; ops
.. _doxid-structgls__ainfo_1af0a337c9f4d03e088123ec071639aad7:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	:ref:`real_wp_<doxid-galahad__precision_8h_1ab82133d435678ff159433d2e50cf295e>` ops

Number of operations in elimination.

