/*
 * Policies
 *
 *    Leonardo Bergesio     <leonardo.bergesio@i2cat.net>
 *    Francesco Salvestrini <f.salvestrini@nextworks.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef RINA_POLICIES_H
#define RINA_POLICIES_H

#include "common.h"

struct p_param;
struct policy;

struct policy *    policy_create(void);
struct policy *    policy_create_ni(void);
struct policy *    policy_create_gfp(gfp_t flags);
int                policy_destroy(struct policy * p);
string_t *         policy_name(struct policy * policy);
int                policy_name_set(struct policy * policy,
                                   string_t *      name);
string_t *         policy_version(struct policy * policy);
int                policy_version_set(struct policy * policy,
                                      string_t *      version);

struct p_param *   policy_param_create(void);
struct p_param *   policy_param_create_ni(void);
int                policy_param_destroy(struct p_param * param);
struct p_param *   policy_param_find_by_name(struct policy * policy,
                                             struct p_param * param);
int                policy_param_is_present(struct policy *  policy,
                                           struct p_param * param);
int                policy_param_add(struct policy *  policy,
                                    struct p_param * param);
int                policy_param_rem(struct policy *  policy,
                                    struct p_param * param);
int                policy_param_rem_and_del(struct policy *  policy,
                                            struct p_param * param);
string_t *         policy_param_name(struct p_param * param);
string_t *         policy_param_value(struct p_param * param);

int                policy_param_name_set(struct p_param * param,
                                         string_t *       name);
int                policy_param_value_set(struct p_param * param,
                                          string_t *       value);

struct list_head * policy_params(struct policy * policy);

#endif
