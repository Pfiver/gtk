#include <string.h>
#include <gtk/gtk.h>

static gboolean
draw_cb_checks (GtkWidget *widget, cairo_t *cr)
{
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (widget);

  gtk_style_context_save (context);

  gtk_style_context_add_class (context, "check");
  gtk_style_context_set_state (context, 0);
  gtk_render_check (context, cr, 12, 12, 12, 12);
  gtk_style_context_set_state (context, GTK_STATE_FLAG_ACTIVE);
  gtk_render_check (context, cr, 36, 12, 12, 12);
  gtk_style_context_set_state (context, GTK_STATE_FLAG_INCONSISTENT);
  gtk_render_check (context, cr, 60, 12, 12, 12);
  gtk_style_context_set_state (context, GTK_STATE_FLAG_INSENSITIVE);
  gtk_render_check (context, cr, 84, 12, 12, 12);

  gtk_style_context_restore (context);

  return TRUE;
}


static gboolean
draw_cb_options (GtkWidget *widget, cairo_t *cr)
{
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (widget);

  gtk_style_context_save (context);

  gtk_style_context_add_class (context, "radio");
  gtk_style_context_set_state (context, 0);
  gtk_render_option (context, cr, 12, 12, 12, 12);
  gtk_style_context_set_state (context, GTK_STATE_FLAG_ACTIVE);
  gtk_render_option (context, cr, 36, 12, 12, 12);
  gtk_style_context_set_state (context, GTK_STATE_FLAG_INCONSISTENT);
  gtk_render_option (context, cr, 60, 12, 12, 12);
  gtk_style_context_set_state (context, GTK_STATE_FLAG_INSENSITIVE);
  gtk_render_option (context, cr, 84, 12, 12, 12);

  gtk_style_context_restore (context);

  return TRUE;
}

static gboolean
draw_cb_arrows (GtkWidget *widget, cairo_t *cr)
{
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (widget);

  gtk_style_context_save (context);

  gtk_style_context_set_state (context, 0);
  gtk_render_arrow (context, cr, 0,        12, 12, 12);
  gtk_render_arrow (context, cr, G_PI/2,   36, 12, 12);
  gtk_render_arrow (context, cr, G_PI,     60, 12, 12);
  gtk_render_arrow (context, cr, G_PI*3/2, 84, 12, 12);

  gtk_style_context_restore (context);

  return TRUE;
}

static gboolean
draw_cb_expanders (GtkWidget *widget, cairo_t *cr)
{
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (widget);

  gtk_style_context_save (context);

  gtk_style_context_add_class (context, "expander");
  gtk_style_context_set_state (context, 0);
  gtk_render_expander (context, cr, 12, 12, 12, 12);
  gtk_style_context_set_state (context, GTK_STATE_FLAG_PRELIGHT);
  gtk_render_expander (context, cr, 36, 12, 12, 12);
  gtk_style_context_set_state (context, GTK_STATE_FLAG_ACTIVE);
  gtk_render_expander (context, cr, 60, 12, 12, 12);
  gtk_style_context_set_state (context, GTK_STATE_FLAG_PRELIGHT | GTK_STATE_FLAG_ACTIVE);
  gtk_render_expander (context, cr, 84, 12, 12, 12);

  gtk_style_context_restore (context);

  return TRUE;
}

static gboolean
draw_cb_background (GtkWidget *widget, cairo_t *cr)
{
  GtkStyleProvider *provider;
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (widget);

  gtk_style_context_save (context);

  provider = (GtkStyleProvider *)gtk_css_provider_new ();
  gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider),
                                   "* {\n"
                                   "   border-radius: 10;\n"
                                   "   border-width: 0;\n"
                                   "   background-image: -gtk-gradient (linear, left top, right bottom, from(#ff00ff), to(#aabbcc));\n"
                                   "}\n", -1, NULL);
  gtk_style_context_add_provider (context, provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  gtk_style_context_set_junction_sides (context, 0);
  gtk_render_background (context, cr, 12, 12, 100, 100);
  gtk_style_context_remove_provider (context, provider);
  gtk_style_context_restore (context);

  return TRUE;
}

static gboolean
draw_cb_frame (GtkWidget *widget, cairo_t *cr)
{
  GtkStyleProvider *provider;
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (widget);

  gtk_style_context_save (context);

  provider = (GtkStyleProvider *)gtk_css_provider_new ();
  gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider),
                                   ".frame1 {\n"
                                   "   border-image: url('gradient1.png') 10 10 10 10 stretch;\n"
                                   "}\n"
                                   ".frame2 {\n"
                                   "   border-style: solid;\n"
                                   "   border-color: rgb(255,0,0);\n"
                                   "   border-width: 10;\n"
                                   "   border-radius: 10;\n"
                                   "}\n"
                                   ".frame3 {\n"
                                   "   border-style: solid;\n"
                                   "   border-color: rgb(0,0,0);\n"
                                   "   border-width: 2;\n"
                                   "   border-radius: 10;\n"
                                   "}\n",
                                   -1, NULL);
  gtk_style_context_add_provider (context, provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

  gtk_style_context_add_class (context, "frame1");
  gtk_style_context_set_junction_sides (context, 0);
  gtk_render_frame (context, cr, 12, 12, 50, 50);
  gtk_style_context_remove_class (context, "frame1");

  gtk_style_context_add_class (context, "frame2");
  gtk_render_frame (context, cr, 74, 12, 50, 50);
  gtk_style_context_remove_class (context, "frame2");

  gtk_style_context_add_class (context, "frame3");
  gtk_style_context_set_junction_sides (context, GTK_JUNCTION_RIGHT);
  gtk_render_frame (context, cr, 12, 74, 56, 50);
  gtk_style_context_set_junction_sides (context, GTK_JUNCTION_LEFT);
  gtk_render_frame (context, cr, 68, 74, 56, 50);
  gtk_style_context_remove_class (context, "frame3");

  gtk_style_context_remove_provider (context, provider);
  gtk_style_context_restore (context);

  return TRUE;
}

/* FIXME: this doesn't work */
static gboolean
draw_cb_activity (GtkWidget *widget, cairo_t *cr)
{
  GtkStyleContext *context;
  GtkWidgetPath *path;

  context = gtk_widget_get_style_context (widget);
  gtk_style_context_notify_state_change (context,
                                         gtk_widget_get_window (widget),
                                         NULL,
                                         GTK_STATE_FLAG_ACTIVE,
                                         TRUE);

  gtk_style_context_save (context);

  path = gtk_widget_path_new ();
  gtk_widget_path_append_type (path, GTK_TYPE_SPINNER);
  gtk_widget_path_iter_add_class (path, 0, "spinner");
  gtk_style_context_set_path (context, path);
  gtk_widget_path_free (path);

  gtk_style_context_set_state (context, GTK_STATE_FLAG_ACTIVE);
  gtk_render_activity (context, cr, 12, 12, 12, 12);

  gtk_style_context_restore (context);

  return TRUE;
}

static gboolean
draw_cb_slider (GtkWidget *widget, cairo_t *cr)
{
  GtkStyleContext *context;
  GtkWidgetPath *path;

  context = gtk_widget_get_style_context (widget);
  gtk_style_context_save (context);

  path = gtk_widget_path_new ();
  gtk_widget_path_append_type (path, GTK_TYPE_SCALE);
  gtk_widget_path_iter_add_class (path, 0, "slider");
  gtk_widget_path_iter_add_class (path, 0, "scale");
  gtk_style_context_set_path (context, path);
  gtk_widget_path_free (path);

  gtk_render_slider (context, cr, 12, 22, 30, 10, GTK_ORIENTATION_HORIZONTAL);
  gtk_render_slider (context, cr, 54, 12, 10, 30, GTK_ORIENTATION_VERTICAL);

  gtk_style_context_restore (context);

  return TRUE;
}

static gboolean
draw_cb_focus (GtkWidget *widget, cairo_t *cr)
{
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (widget);

  gtk_style_context_save (context);

  gtk_render_focus (context, cr, 12, 12, 50, 50);

  gtk_style_context_restore (context);

  return TRUE;
}

static gboolean
draw_cb_extension (GtkWidget *widget, cairo_t *cr)
{
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (widget);

  gtk_style_context_save (context);

  gtk_style_context_add_class (context, "notebook");
  gtk_style_context_add_region (context, GTK_STYLE_REGION_TAB, 0);

  gtk_style_context_set_state (context, 0);
  gtk_render_extension (context, cr, 26, 12, 24, 12, GTK_POS_BOTTOM);
  gtk_render_extension (context, cr, 12, 26, 12, 24, GTK_POS_RIGHT);
  gtk_render_extension (context, cr, 26, 52, 24, 12, GTK_POS_TOP);
  gtk_render_extension (context, cr, 52, 26, 12, 24, GTK_POS_LEFT);

  gtk_style_context_restore (context);

  return TRUE;
}

static char *what;

static gboolean
draw_cb (GtkWidget *widget, cairo_t *cr)
{
  if (strcmp (what, "check") == 0)
    return draw_cb_checks (widget, cr);
  else if (strcmp (what, "option") == 0)
    return draw_cb_options (widget, cr);
  else if (strcmp (what, "arrow") == 0)
    return draw_cb_arrows (widget, cr);
  else if (strcmp (what, "expander") == 0)
    return draw_cb_expanders (widget, cr);
  else if (strcmp (what, "background") == 0)
    return draw_cb_background (widget, cr);
  else if (strcmp (what, "frame") == 0)
    return draw_cb_frame (widget, cr);
  else if (strcmp (what, "activity") == 0)
    return draw_cb_activity (widget, cr);
  else if (strcmp (what, "slider") == 0)
    return draw_cb_slider (widget, cr);
  else if (strcmp (what, "focus") == 0)
    return draw_cb_focus (widget, cr);
  else if (strcmp (what, "extension") == 0)
    return draw_cb_extension (widget, cr);

  return FALSE;
}

int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *ebox;

  gtk_init (&argc, &argv);

  if (argc > 1)
    what = argv[1];
  else
    what = "check";

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_has_resize_grip (GTK_WINDOW (window), FALSE);
  ebox = gtk_event_box_new ();
  gtk_event_box_set_visible_window (GTK_EVENT_BOX (ebox), TRUE);
  gtk_container_add (GTK_CONTAINER (window), ebox);
  gtk_widget_set_name (ebox, "ebox");
  g_signal_connect_after (ebox, "draw", G_CALLBACK (draw_cb), NULL);

  gtk_widget_show_all (window);

  gtk_main ();

  return 0;
}
