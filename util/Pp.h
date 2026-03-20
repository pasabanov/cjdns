/* vim: set expandtab ts=4 sw=4: */
/*
 * You may redistribute this program and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef Pp_H
#define Pp_H

// Preprocessor which runs after the CPP as part of the build.
// See execJs in builder.js for the list of functions.

// Pp_Q is defined directly in builder.js because
// you cannot define " as a macro without the compiler complaining.

#define Pp_expr(or, func, ...) or
#define Pp_stmt(func, ...)

#if !defined(__INTELLISENSE__) && !defined(BINDGEN)
    #undef Pp_expr
    #define Pp_expr(or, ...) __CJDNS_JS_FUNC__( __VA_ARGS__ )__CJDNS_END_JS_FUNC__
    #undef Pp_stmt
    #define Pp_stmt(...) __CJDNS_JS_FUNC__( __VA_ARGS__ )__CJDNS_END_JS_FUNC__
#endif

#endif
