/*
 * Policies common structures
 *
 *    Leonardo Bergesio     <leonardo.bergesio@i2cat.net>
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


#define RINA_PREFIX "policies"

#include <linux/list.h>

#include "policies.h"
#include "utils.h"
#include "logs.h"

struct p_param {
        char *           name;
        char *           value;
        struct list_head next;
};

struct policy {
        char *           name;
        char *           version;
        struct list_head params;
};

static struct policy * policies_create_gfp(gfp_t flags) 
{
        struct policy * tmp;

        tmp = rkmalloc(sizeof(*tmp), flags);
        if (!tmp)
                return NULL;

        INIT_LIST_HEAD(&tmp->params);

        return tmp;
}

struct policy * policy_create()
{ return policies_create_gfp(GFP_KERNEL); }
EXPORT_SYMBOL(policy_create);

struct policy * policy_create_ni()
{ return policies_create_gfp(GFP_ATOMIC); }
EXPORT_SYMBOL(policy_create_ni);

static struct p_param * policy_param_create_gfp(gfp_t flags) 
{
        struct p_param * tmp;

        tmp = rkmalloc(sizeof(*tmp), flags);
        if (!tmp)
                return NULL;

        INIT_LIST_HEAD(&tmp->next);

        return tmp;
}

struct p_param * policy_param_create()
{ return policy_param_create_gfp(GFP_KERNEL); }
EXPORT_SYMBOL(policy_param_create);
                                           
struct p_param * policy_param_create_ni()
{ return policy_param_create_gfp(GFP_ATOMIC); }
EXPORT_SYMBOL(policy_param_create_ni);

int policy_param_add (struct policy *  policy,
                      struct p_param * param)
{ 
        LOG_MISSING;
        return 0;
}
EXPORT_SYMBOL(policy_param_add);

int policy_param_rem(struct policy *  policy,
                     struct p_param * param)
{ 
        LOG_MISSING;
        return 0;
}
EXPORT_SYMBOL(policy_param_rem);

