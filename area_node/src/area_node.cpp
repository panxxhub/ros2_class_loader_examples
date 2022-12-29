#include <memory>
#include <pluginlib/class_loader.hpp>
#include <polygon_base/regular_polygon.hpp>

auto main(int argc, char ** argv) -> int
{
  // To avoid unused parameter warnings
  (void)argc;
  (void)argv;

  try
  {
    pluginlib::ClassLoader<polygon_base::RegularPolygon> poly_loader(
      "polygon_base", "polygon_base::RegularPolygon");

    auto sq_ptr = std::unique_ptr<polygon_base::RegularPolygon>(
      poly_loader.createUnmanagedInstance("polygon_plugins::Square"));
    sq_ptr->initialize(10.0);
    auto sq_ptr2 = std::unique_ptr<polygon_base::RegularPolygon>(
      poly_loader.createUnmanagedInstance("polygon_plugins::Square"));
    sq_ptr2->initialize(12.0);

    printf("Square area: %.2f\n", sq_ptr->area());
    printf("Square area: %.2f\n", sq_ptr2->area());
  }
  catch (pluginlib::PluginlibException & ex)
  {
    printf("The plugin failed to load for some reason. Error: %s\n", ex.what());
  }

  return 0;
}