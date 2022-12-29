#ifndef POLYGON_BASE_REGULAR_POLYGON_HPP
#define POLYGON_BASE_REGULAR_POLYGON_HPP

namespace polygon_base
{
class RegularPolygon
{
public:
  virtual void initialize(double side_length) = 0;
  virtual auto area() -> double = 0;
  virtual ~RegularPolygon() = default;

protected:
  RegularPolygon() = default;
};
}  // namespace polygon_base

#endif  // POLYGON_BASE_REGULAR_POLYGON_HPP