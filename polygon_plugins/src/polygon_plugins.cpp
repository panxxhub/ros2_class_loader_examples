#include "polygon_plugins/polygon_plugins.hpp"
namespace
{

double base = 1.0;

}

namespace polygon_plugins
{

void Square::initialize(double side_length) { base = side_length; }
auto Square::area() -> double { return base * base; }

}  // namespace polygon_plugins

#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(polygon_plugins::Square, polygon_base::RegularPolygon)
PLUGINLIB_EXPORT_CLASS(polygon_plugins::Triangle, polygon_base::RegularPolygon)