.. index:: pair: struct; gls_sinfo
.. _doxid-structgls__sinfo:

gls_sinfo structure
-------------------

.. toctree::
	:hidden:

.. ref-code-block:: cpp
	:class: doxyrest-overview-code-block

	#include <galahad_gls.h>
	
	struct gls_sinfo {
		// fields
	
		int :ref:`flag<doxid-structgls__sinfo_1adf916204820072417ed73a32de1cefcf>`;
		int :ref:`more<doxid-structgls__sinfo_1a4628f2fb17af64608416810cc4e5a9d0>`;
		int :ref:`stat<doxid-structgls__sinfo_1a7d6f8a25e94209bd3ba29b2051ca4f08>`;
	};
.. _details-structgls__sinfo:

detailed documentation
----------------------

sinfo derived type as a C struct

components
~~~~~~~~~~

.. index:: pair: variable; flag
.. _doxid-structgls__sinfo_1adf916204820072417ed73a32de1cefcf:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int flag

Flags success or failure case.

.. index:: pair: variable; more
.. _doxid-structgls__sinfo_1a4628f2fb17af64608416810cc4e5a9d0:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int more

More information on failure.

.. index:: pair: variable; stat
.. _doxid-structgls__sinfo_1a7d6f8a25e94209bd3ba29b2051ca4f08:

.. ref-code-block:: cpp
	:class: doxyrest-title-code-block

	int stat

Status value after allocate failure.

