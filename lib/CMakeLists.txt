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

include(../cmake/GitModules.cmake)

add_definitions("-DGSL_TERMINATE_ON_CONTRACT_VIOLATION=1 -DGSL_MSVC_USE_STL_NOEXCEPTION_WORKAROUND")

set (DISABLE_TESTS ON)

fetch_module_via_tag(lib/gsl/gsl ${PROJECT_SOURCE_DIR}/lib/gsl/gsl ${PROJECT_SOURCE_DIR} "v2.1.0")
fetch_module_via_branch(lib/eul ${PROJECT_SOURCE_DIR}/lib/eul ${PROJECT_SOURCE_DIR} "master")
