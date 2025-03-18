#include <cairo/cairo.h>
#include <cmath>
#include <gtk/gtk.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Vec2 {
  double x, y;
};

class Shape {
public:
  virtual void draw(cairo_t *cr, bool selected) const = 0;
  virtual ~Shape() = default;
  virtual void update(const Vec2 &start, const Vec2 &end) = 0;
  virtual bool collide(const Vec2 &point) = 0;
  virtual void drag(const Vec2 &start, const Vec2 &end) = 0;
  std::vector<Shape *> children;
};

enum class DrawMode { POINTER, RECTANGLE, LINE, CIRCLE, TEXT };

struct AppData {
  Vec2 pan{0.0, 0.0};
  Vec2 pan_start{0.0, 0.0};
  bool is_dragging{false};
  bool is_panning{false};
  double zoom{1.0};
  GdkRGBA selected_color{0.0, 0.0, 0.0, 1.0};
  DrawMode draw_mode{DrawMode::POINTER};
  Vec2 start{0.0, 0.0};
  Vec2 current_pos{0.0, 0.0};
  std::vector<Shape *> shapes;
  std::string displayText{"Hello, World!"};
  GtkWidget *drawing_area;
  Shape *selected_shape{nullptr};
} model;
