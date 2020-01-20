# This file is part of MSOS project. This is simple OS for embedded development devices.
# Copyright (C) 2020 Mateusz Stadnik
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

file(GLOB_RECURSE gsl_srcs
    "gsl/include/*."
    )

set(Gsl_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/gsl/gsl/include" CACHE STRING "path to GSL sources" FORCE)

add_library(gsl INTERFACE)
target_sources(gsl INTERFACE ${gsl_srcs})
target_include_directories(gsl INTERFACE ${Gsl_INCLUDE_DIR})
