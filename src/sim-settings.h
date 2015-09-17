/*
 * sim-settings.h
 *
 *
 * Authors:
 *  Richard Hult <rhult@hem.passagen.se>
 *  Ricardo Markiewicz <rmarkie@fi.uba.ar>
 *  Andres de Barbara <adebarbara@fi.uba.ar>
 *  Marc Lorber <lorber.marc@wanadoo.fr>
 *
 * Web page: https://ahoi.io/project/oregano
 *
 * Copyright (C) 1999-2001  Richard Hult
 * Copyright (C) 2003,2004  Ricardo Markiewicz
 * Copyright (C) 2009-2012  Marc Lorber
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __SIM_SETTINGS_H
#define __SIM_SETTINGS_H

#include <gtk/gtk.h>

typedef struct _SimSettings SimSettings;

#include "schematic-view.h"
#include "schematic.h"

typedef struct _SimSettingsPriv SimSettingsPriv;

struct _SimSettings
{
	Schematic *sm;
	GtkWidget *pbox;
	GtkNotebook *notebook;
	SimSettingsPriv *priv;
};

typedef struct _SimOption SimOption;

struct _SimOption
{
	gchar *name;
	gchar *value;
} _SimOption;

void sim_settings_show (GtkWidget *widget, SchematicView *sv);

SimSettings *sim_settings_new (Schematic *sm);

gdouble sim_settings_get_trans_start (SimSettings *sim_settings);

gdouble sim_settings_get_trans_stop (SimSettings *sim_settings);

gdouble sim_settings_get_trans_step (SimSettings *sim_settings);

gboolean sim_settings_get_trans (SimSettings *sim_settings);

gdouble sim_settings_get_trans_step_enable (SimSettings *sim_settings);

gboolean sim_settings_get_trans_init_cond (SimSettings *sim_settings);

void sim_settings_set_trans_start (SimSettings *sim_settings, gchar *str);

void sim_settings_set_trans_stop (SimSettings *sim_settings, gchar *str);

void sim_settings_set_trans_step (SimSettings *sim_settings, gchar *str);

void sim_settings_set_trans (SimSettings *sim_settings, gboolean enable);

void sim_settings_set_trans_step_enable (SimSettings *sim_settings, gboolean enable);

void sim_settings_set_trans_init_cond (SimSettings *sim_settings, gboolean enable);

gboolean sim_settings_get_dc (SimSettings *);

gchar *sim_settings_get_dc_vsrc (SimSettings *);

gdouble sim_settings_get_dc_start (SimSettings *);

gdouble sim_settings_get_dc_stop (SimSettings *);

gdouble sim_settings_get_dc_step (SimSettings *);

void sim_settings_set_dc (SimSettings *, gboolean);

void sim_settings_set_dc_vsrc (SimSettings *, gchar *);

void sim_settings_set_dc_start (SimSettings *, gchar *);

void sim_settings_set_dc_stop (SimSettings *, gchar *);

void sim_settings_set_dc_step (SimSettings *, gchar *);

gboolean sim_settings_get_ac (SimSettings *);

gchar *sim_settings_get_ac_type (SimSettings *);

gint sim_settings_get_ac_npoints (SimSettings *);

gdouble sim_settings_get_ac_start (SimSettings *);

gdouble sim_settings_get_ac_stop (SimSettings *);

void sim_settings_set_ac (SimSettings *, gboolean);

void sim_settings_set_ac_type (SimSettings *, gchar *);

void sim_settings_set_ac_npoints (SimSettings *, gchar *);

void sim_settings_set_ac_start (SimSettings *, gchar *);

void sim_settings_set_ac_stop (SimSettings *, gchar *);

void sim_settings_set_fourier (SimSettings *, gboolean);

void sim_settings_set_fourier_frequency (SimSettings *, gchar *);

void sim_settings_set_fourier_vout (SimSettings *, gchar *);

gboolean sim_settings_get_fourier (SimSettings *);

gint sim_settings_get_fourier_frequency (SimSettings *);

gchar *sim_settings_get_fourier_vout (SimSettings *);

gchar *sim_settings_get_fourier_nodes (SimSettings *);

GList *sim_settings_get_options (SimSettings *sim_settings);

void sim_settings_add_option (SimSettings *, SimOption *);

#endif
