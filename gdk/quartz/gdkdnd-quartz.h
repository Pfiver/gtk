/* gdkdnd-quartz.h
 *
 * Copyright (C) 2010 Kristian Rietveld  <kris@gtk.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GDK_QUARTZ_DND_H__
#define __GDK_QUARTZ_DND_H__

#include <gdk/gdk.h>
#include <gdk/quartz/gdkquartz.h>
#include <gdk/gdkdndprivate.h>

G_BEGIN_DECLS

#define GDK_TYPE_QUARTZ_DRAG_CONTEXT              (gdk_quartz_drag_context_get_type ())
#define GDK_QUARTZ_DRAG_CONTEXT(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_QUARTZ_DRAG_CONTEXT, GdkQuartzDragContext))
#define GDK_QUARTZ_DRAG_CONTEXT_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GDK_TYPE_QUARTZ_DRAG_CONTEXT, GdkQuartzDragContextClass))
#define GDK_IS_QUARTZ_DRAG_CONTEXT(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_QUARTZ_DRAG_CONTEXT))
#define GDK_IS_QUARTZ_DRAG_CONTEXT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GDK_TYPE_QUARTZ_DRAG_CONTEXT))
#define GDK_QUARTZ_DRAG_CONTEXT_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GDK_TYPE_QUARTZ_DRAG_CONTEXT, GdkQuartzDragContextClass))

typedef struct _GdkQuartzDragContext GdkQuartzDragContext;
typedef struct _GdkQuartzDragContextClass GdkQuartzDragContextClass;

struct _GdkQuartzDragContext
{
  GdkDragContext context;

  id <NSDraggingInfo> dragging_info;
  GdkDevice *device;
};

struct _GdkQuartzDragContextClass
{
  GdkDragContextClass context_class;
};

GType gdk_quartz_drag_context_get_type (void);

G_END_DECLS

#endif /* __GDK_QUARTZ_DRAG_CONTEXT_H__ */