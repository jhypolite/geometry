// Boost.Geometry (aka GGL, Generic Geometry Library)
//
// Copyright Barend Gehrels 2007-2010, Geodan, Amsterdam, the Netherlands.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_ALGORITHMS_DETAIL_OVERLAY_CONVERT_RING_HPP
#define BOOST_GEOMETRY_ALGORITHMS_DETAIL_OVERLAY_CONVERT_RING_HPP


#include <boost/range.hpp>


#include <boost/geometry/core/tags.hpp>
#include <boost/geometry/core/exterior_ring.hpp>
#include <boost/geometry/core/interior_rings.hpp>
#include <boost/geometry/algorithms/detail/ring_identifier.hpp>

#include <boost/geometry/algorithms/convert.hpp>


namespace boost { namespace geometry
{


#ifndef DOXYGEN_NO_DETAIL
namespace detail { namespace overlay
{


template<typename Tag>
struct convert_ring
{};

template<>
struct convert_ring<ring_tag>
{
    template<typename Destination, typename Source>
    static inline void apply(Destination& destination, Source const& source,
                bool append = false)
    {
        if (! append)
        {
            geometry::convert(source, destination);
        }
    }
};


template<>
struct convert_ring<polygon_tag>
{
    template<typename Destination, typename Source>
    static inline void apply(Destination& destination, Source const& source,
                bool append = false)
    {
        if (! append)
        {
            geometry::convert(source, exterior_ring(destination));
        }
        else
        {
            interior_rings(destination).resize(
                        interior_rings(destination).size() + 1);
            geometry::convert(source, interior_rings(destination).back());
        }
    }
};


}} // namespace detail::overlay
#endif // DOXYGEN_NO_DETAIL


}} // namespace boost::geometry


#endif // BOOST_GEOMETRY_ALGORITHMS_DETAIL_OVERLAY_CONVERT_RING_HPP
