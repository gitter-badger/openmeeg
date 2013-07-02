/*
Project Name : OpenMEEG

© INRIA and ENPC (contributors: Geoffray ADDE, Maureen CLERC, Alexandre 
GRAMFORT, Renaud KERIVEN, Jan KYBIC, Perrine LANDREAU, Théodore PAPADOPOULO,
Emmanuel OLIVI
Maureen.Clerc.AT.sophia.inria.fr, keriven.AT.certis.enpc.fr,
kybic.AT.fel.cvut.cz, papadop.AT.sophia.inria.fr)

The OpenMEEG software is a C++ package for solving the forward/inverse
problems of electroencephalography and magnetoencephalography.

This software is governed by the CeCILL-B license under French law and
abiding by the rules of distribution of free software.  You can  use,
modify and/ or redistribute the software under the terms of the CeCILL-B
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info".

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's authors,  the holders of the
economic rights,  and the successive licensors  have only  limited
liability.

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or
data to be ensured and,  more generally, to use and operate it in the
same conditions as regards security.

The fact that you are presently reading this means that you have had
knowledge of the CeCILL-B license and that you accept its terms.
*/

#ifndef OPENMEEG_INTERFACE_H
#define OPENMEEG_INTERFACE_H

#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include "mesh.h"

namespace OpenMEEG {

    /** \brief  Interface

        Interface class

    **/

    class OPENMEEG_EXPORT Interface: public std::vector<Mesh *> {

    public:

        Interface(): name_(""), outermost_(false) { }
        Interface(std::string name): name_(name), outermost_(false) { }

        ~Interface() { }

        const std::string   name() const               { return name_; }
              std::string & name()                     { return name_; }

        bool          outermost()      const           { return outermost_; }

        const size_t  nb_triangles()    const          { 
            size_t nb = 0;
            for (const_iterator mit = begin(); mit != end(); mit++) {
                nb += (*mit)->nb_triangles();
            }
            return nb;
        }

        const size_t  nb_vertices()    const          { 
            size_t nb = 0;
            for (const_iterator mit = begin(); mit != end(); mit++) {
                nb += (*mit)->nb_vertices();
            }
            return nb;
        }

        bool          contains_point(const Vect3&) const;
        void          set_to_outermost();

    private:

        std::string name_;      // might be "i0" by default
        bool        outermost_; // tell weather or not the interface touches the Air (Outermost) domain.
    };

    typedef std::vector<Interface> Interfaces;
}

#endif  //  ! OPENMEEG_INTERFACE_H


