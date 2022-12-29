#ifndef POLYGON_PLUGINS__POLYGON_PLUGINS_HPP_
#define POLYGON_PLUGINS__POLYGON_PLUGINS_HPP_

#include <cmath>
#include <polygon_base/regular_polygon.hpp>
#include "polygon_plugins/visibility_control.h"

namespace polygon_plugins
{

class Square : public polygon_base::RegularPolygon
{
public:
  void initialize(double side_length) override;

  auto area() -> double override;
};

class Triangle : public polygon_base::RegularPolygon
{
public:
  void initialize(double side_length) override { side_length_ = side_length; }

  auto area() -> double override { return 0.5 * side_length_ * get_height(); }

  auto get_height() const -> double
  {
    return std::sqrt((side_length_ * side_length_) - ((side_length_ / 2) * (side_length_ / 2)));
  }

protected:
  double side_length_;
};

}  // namespace polygon_plugins

#endif  // POLYGON_PLUGINS__POLYGON_PLUGINS_HPP_
