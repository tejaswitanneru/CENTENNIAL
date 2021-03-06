
/* 
 * Copyright (c) 2008-2012, Andy Bierman, All Rights Reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *

*** Generated by yangdump 2.5-5

    User SIL module
    module MicrowaveModel-ObjectClasses-PureEthernetStructure
    revision 2016-09-02
    namespace uri:onf:MicrowaveModel-ObjectClasses-PureEthernetStructure
    organization ONF (Open Networking Foundation) Open Transport Working Group - Wireless Transport Project

 */

#include <xmlstring.h>

#include "procdefs.h"
#include "agt.h"
#include "agt_cb.h"
#include "agt_timer.h"
#include "agt_util.h"
#include "dlq.h"
#include "ncx.h"
#include "ncx_feature.h"
#include "ncxmod.h"
#include "ncxtypes.h"
#include "status.h"
#include "u_microwave-model.h"
#include "y_microwave-model.h"

#include "utils.h"
#include "ses.h"
#include "rpc.h"
#include "runtime_callbacks.h"
#include "configuration_callbacks.h"

/* put your static variables here */

#undef VAL_INT16
#define VAL_INT16(V)   ((V)->v.num.i)


static status_t attach_pure_eth_structure_element_to_running_config(cfg_template_t* runningcfg, const char* air_pure_eth_structure_key);

static status_t attach_pure_eth_structure_capability_container(val_value_t *parentval);

static status_t attach_pure_eth_structure_configuration_container(val_value_t *parentval);
static status_t attach_problem_kind_severity_list(val_value_t* parentval);
static status_t attach_problem_kind_severity_list_entry(val_value_t* parentval, const char* problem_kind_severity_list_key_entry);

static status_t get_pure_eth_structure_current_problem_list(ses_cb_t *scb, getcb_mode_t cbmode, val_value_t *vir_val, val_value_t *dst_val);
static status_t attach_current_problem_list_entry(val_value_t* parentval, const char* pure_eth_structure_current_problem_list_key_entry);

static status_t build_attributes_tree_and_attach_to_running_cfg(cfg_template_t* runningcfg)
{
	status_t res = NO_ERR;
    char* air_pure_eth_structure_keys_list[MAX_NUMBER_OF_PURE_ETHERNET_STRUCTURE_ENTRIES];
    int num_of_pure_eth_structure_pac_keys;

	/*
	 * Getting all the interfaces of the system
	 */
	res = cb_get_all_pure_eth_structure_pac_keys(air_pure_eth_structure_keys_list, &num_of_pure_eth_structure_pac_keys);
	YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL, "cb_get_all_pure_eth_structure_pac_keys failed!");

	for (int i=0; i<num_of_pure_eth_structure_pac_keys; ++i)
	{
		/*
		 * Attaching a mw_pure_ethernet_structure_pac list entry
		 */
		res = attach_pure_eth_structure_element_to_running_config(runningcfg, air_pure_eth_structure_keys_list[i]);
		YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL, "attach_pure_eth_structure_element_to_running_config failed!");

		free(air_pure_eth_structure_keys_list[i]);
	}

	return NO_ERR;
}

static status_t attach_pure_eth_structure_element_to_running_config(cfg_template_t* runningcfg, const char* air_pure_eth_structure_key)
{
	status_t res = NO_ERR;

	/*
	 * Creating the root element for the module: mw_pure_ethernet_structure_pac
	 */
	val_value_t *mw_pure_ethernet_structure_pac_val = NULL;

                                         
	res = create_root_element_for_module(y_microwave_model_M_microwave_model,
			y_microwave_model_R_microwave_model,
			y_microwave_model_N_mw_pure_ethernet_structure_pac,
			&mw_pure_ethernet_structure_pac_val);
	YUMA_ASSERT(NULL == mw_pure_ethernet_structure_pac_val, return ERR_INTERNAL_VAL ,
			"create_root_element_for_module failed for element=%s", y_microwave_model_N_mw_pure_ethernet_structure_pac);

	val_add_child(mw_pure_ethernet_structure_pac_val, runningcfg->root);

	/*
	 * Creating the layer_protocol element
	 */
	val_value_t  *layer_protocol_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_layer_protocol,
			mw_pure_ethernet_structure_pac_val,
			&layer_protocol_val,
			air_pure_eth_structure_key,
			y_microwave_model_M_microwave_model,
			false);
	YUMA_ASSERT(NULL == layer_protocol_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_layer_protocol);

	/*
	 * Creating pureEthernetStructureCapability container
	 */
	val_value_t  *pureEthernetStructureCapability_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_pure_ethernet_structure_capability,
			mw_pure_ethernet_structure_pac_val,
			&pureEthernetStructureCapability_val,
			NULL,
			y_microwave_model_M_microwave_model,
			false);
	YUMA_ASSERT(NULL == pureEthernetStructureCapability_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_pure_ethernet_structure_capability);

	/*
	 * Creating all the leaf elements of the pureEthernetStructureCapability container
	 */
	res = attach_pure_eth_structure_capability_container(pureEthernetStructureCapability_val);
	YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL ,
					"attach_pure_eth_structure_capability_container failed for layer_protocol=%s", air_pure_eth_structure_key);

	/*
	 * Creating pureEthernetStructureConfiguration container
	 */
	val_value_t  *pureEthernetStructureConfiguration_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_pure_ethernet_structure_configuration,
			mw_pure_ethernet_structure_pac_val,
			&pureEthernetStructureConfiguration_val,
			NULL,
			y_microwave_model_M_microwave_model,
			false);
	YUMA_ASSERT(NULL == pureEthernetStructureConfiguration_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_pure_ethernet_structure_configuration);

	res = attach_pure_eth_structure_configuration_container(pureEthernetStructureConfiguration_val);
	YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL ,
					"attach_pure_eth_structure_configuration_container failed for layer_protocol=%s", air_pure_eth_structure_key);

	/*
	 * Creating pureEthernetStructureStatus container
	 */
	val_value_t  *pureEthernetStructureStatus_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_pure_ethernet_structure_status,
			mw_pure_ethernet_structure_pac_val,
			&pureEthernetStructureStatus_val,
			NULL,
			y_microwave_model_M_microwave_model,
			true);
	YUMA_ASSERT(NULL == pureEthernetStructureStatus_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_pure_ethernet_structure_status);


	res = microwave_model_mw_pure_ethernet_structure_pac_pure_ethernet_structure_status_mro(pureEthernetStructureStatus_val);
	YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL ,
					"microwave_model_mw_air_interface_pac_pure_ethernet_structure_status_mro failed");
	/*
	 * Creating pureEthernetStructureCurrentProblems container
	 */
	val_value_t *pureEthernetStructureCurrentProblems_val = NULL;

	res = agt_add_container(y_microwave_model_M_microwave_model,
			y_microwave_model_N_pure_ethernet_structure_current_problems,
			mw_pure_ethernet_structure_pac_val,
			&pureEthernetStructureCurrentProblems_val);
	YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL ,
						"agt_make_container failed for obj=%s", y_microwave_model_N_pure_ethernet_structure_current_problems);

	val_init_virtual(pureEthernetStructureCurrentProblems_val,
					get_pure_eth_structure_current_problem_list,
					pureEthernetStructureCurrentProblems_val->obj);

	return NO_ERR;
}

static status_t attach_pure_eth_structure_capability_container(val_value_t *parentval)
{
	status_t res = NO_ERR;

	/*
	 * Creating structureId leaf
	 */
	val_value_t  *structureId_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_structure_id,
			parentval,
			&structureId_val,
			NULL,
			y_microwave_model_M_microwave_model,
			false);
	YUMA_ASSERT(NULL == structureId_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_structure_id);

	/*
	 * Create all other leafs after structureId
	 */
	obj_template_t *next_obj = NULL;
	next_obj = obj_next_child(obj_find_child(parentval->obj,
			y_microwave_model_M_microwave_model,
			y_microwave_model_N_structure_id));

	res = create_and_init_siblings(next_obj,
			parentval,
			y_microwave_model_M_microwave_model,
			false);
	YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL, "create_and_init_siblings failed!");


	return NO_ERR;

}

static status_t attach_pure_eth_structure_configuration_container(val_value_t *parentval)
{
	status_t res = NO_ERR;

	/*
	 * Create all leafs
	 */

	res = attach_problem_kind_severity_list(parentval);
	YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL, "attach_pure_ethernet_structure_problem_kind_severity_list failed!");

	return NO_ERR;
}

static status_t attach_problem_kind_severity_list(val_value_t* parentval)
{
	status_t res = NO_ERR;
	char* problem_kind_name[MAX_NUMBER_OF_PROBLEM_KIND_SEVERITY_ENTRIES];
	int num_of_problem_kind_name_keys;

	val_value_t *lastkey = NULL;
	const xmlChar *k_mw_pure_ethernet_structure_pac_layer_protocol_key = VAL_STRING(agt_get_key_value(parentval, &lastkey));

	//the layer_protocol value that we have here is of form: LP-MWS-index
	//if we search for the problem kind in the AirInterface model, we need to translate this index in the form: LP-MWPS-index

	char ifIndex[1000];
	char new_layer_protocol[3000];
	int foundIfIndex = 0;

	foundIfIndex = sscanf(k_mw_pure_ethernet_structure_pac_layer_protocol_key, LP_MWS_PREFIX"%s", ifIndex);

	sprintf(new_layer_protocol, "%s%s", LP_MWPS_PREFIX, ifIndex);

	res = cb_get_all_pure_ethernet_structure_problem_kind_severity_list_keys((foundIfIndex == 0) ? k_mw_pure_ethernet_structure_pac_layer_protocol_key : new_layer_protocol, problem_kind_name, &num_of_problem_kind_name_keys);
	YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL, "cb_get_all_problem_kind_severity_list_keys failed!");

	for (int i=0; i<num_of_problem_kind_name_keys; ++i)
	{
		res = attach_problem_kind_severity_list_entry(parentval, problem_kind_name[i]);
		YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL,
				"attach_problem_kind_severity_list_entry failed for layer_protocol=%s and key=%s!", k_mw_pure_ethernet_structure_pac_layer_protocol_key, problem_kind_name[i]);

		free(problem_kind_name[i]);
	}

	return NO_ERR;
}

static status_t attach_problem_kind_severity_list_entry(val_value_t* parentval, const char* problem_kind_severity_list_key_entry)
{
	status_t res = NO_ERR;

	/*
	 * Creating problemKindSeverityList list entry
	 */
	val_value_t  *problemKindSeverityList_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_problem_kind_severity_list,
			parentval,
			&problemKindSeverityList_val,
			NULL,
			y_microwave_model_M_microwave_model,
			false);
	YUMA_ASSERT(NULL == problemKindSeverityList_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_problem_kind_severity_list);

	/*
	 * Creating problemKindName leaf
	 */
	val_value_t  *problemKindName_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_problem_kind_name,
			problemKindSeverityList_val,
			&problemKindName_val,
			problem_kind_severity_list_key_entry,
			y_microwave_model_M_microwave_model,
			false);
	YUMA_ASSERT(NULL == problemKindName_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_problem_kind_name);

	/*
	 * Creating problemKindSeverity leaf
	 */
	val_value_t  *problemKindSeverity_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_problem_kind_severity,
			problemKindSeverityList_val,
			&problemKindSeverity_val,
			NULL,
			y_microwave_model_M_microwave_model,
			false);
	YUMA_ASSERT(NULL == problemKindSeverity_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_problem_kind_severity);

	return NO_ERR;
}

static status_t get_pure_eth_structure_current_problem_list(ses_cb_t *scb, getcb_mode_t cbmode, val_value_t *vir_val, val_value_t *dst_val)
{
	status_t res = NO_ERR;
	char* pure_eth_structure_current_problem_list_keys_entries[MAX_NUMBER_OF_PURE_ETHERNET_STRUCTURE_CURRENT_PROBLEM_LIST_ENTRIES];
	int num_of_pure_eth_structure_current_problem_list_keys;

	val_value_t *lastkey = NULL;
	const xmlChar *k_mw_pure_ethernet_structure_pac_layer_protocol = VAL_STRING(agt_get_key_value(dst_val, &lastkey));

    char ifIndex[1000];
    char new_layer_protocol[3000];
    int foundIfIndex = 0;

    foundIfIndex = sscanf(k_mw_pure_ethernet_structure_pac_layer_protocol, LP_MWS_PREFIX"%s", ifIndex);

    sprintf(new_layer_protocol, "%s%s", LP_MWPS_PREFIX, ifIndex);

	res = cb_get_all_pure_eth_structure_current_problem_list_keys((foundIfIndex == 0) ? k_mw_pure_ethernet_structure_pac_layer_protocol : new_layer_protocol, pure_eth_structure_current_problem_list_keys_entries, &num_of_pure_eth_structure_current_problem_list_keys);
	YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL, "cb_get_all_air_interface_current_problem_list_keys failed!");

	for (int i=0; i<num_of_pure_eth_structure_current_problem_list_keys; ++i)
	{
		res = attach_current_problem_list_entry(dst_val, pure_eth_structure_current_problem_list_keys_entries[i]);
		YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL,
				"attach_pure_eth_structure_current_problem_list_entry failed for key=%s!", pure_eth_structure_current_problem_list_keys_entries[i]);

		free(pure_eth_structure_current_problem_list_keys_entries[i]);
	}

	return NO_ERR;
}

static status_t attach_current_problem_list_entry(val_value_t* parentval, const char* pure_eth_structure_current_problem_list_key_entry)
{
	status_t res = NO_ERR;

	/*
	 * Create currentProblemList list entry
	 */

	val_value_t  *currentProblemList_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_current_problem_list,
			parentval,
			&currentProblemList_val,
			NULL,
			y_microwave_model_M_microwave_model,
			true);
	YUMA_ASSERT(NULL == currentProblemList_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_current_problem_list);

	/*
	 * Create sequenceNumber leaf
	 */
	val_value_t  *sequenceNumber_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_sequence_number,
			currentProblemList_val,
			&sequenceNumber_val,
			pure_eth_structure_current_problem_list_key_entry,
			y_microwave_model_M_microwave_model,
			true);
	YUMA_ASSERT(NULL == sequenceNumber_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_sequence_number);

    /*
     * Create timeStamp virtual leaf with callback attached
     */
	val_value_t  *timeStamp_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_time_stamp,
			currentProblemList_val,
			&timeStamp_val,
			pure_eth_structure_current_problem_list_key_entry,
			y_microwave_model_M_microwave_model,
			true);
	YUMA_ASSERT(NULL == timeStamp_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_time_stamp);

	/*
     * Create problemName virtual leaf with callback attached
     */
	val_value_t  *problemName_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_problem_name,
			currentProblemList_val,
			&problemName_val,
			pure_eth_structure_current_problem_list_key_entry,
			y_microwave_model_M_microwave_model,
			true);
	YUMA_ASSERT(NULL == problemName_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_problem_name);

    /*
     * Create problemSeverity virtual leaf with callback attached
     */
	val_value_t  *problemSeverity_val = NULL;

	res = create_and_init_child_element(y_microwave_model_M_microwave_model,
			y_microwave_model_N_problem_severity,
			currentProblemList_val,
			&problemSeverity_val,
			pure_eth_structure_current_problem_list_key_entry,
			y_microwave_model_M_microwave_model,
			true);
	YUMA_ASSERT(NULL == problemSeverity_val, return ERR_INTERNAL_VAL ,
				"create_and_init_child_element failed for element=%s", y_microwave_model_N_problem_severity);

	return NO_ERR;
}

status_t build_pure_ethernet_structure_attributes_tree (void)
{
    status_t res = NO_ERR;

    /*
     * Creating the running datastore
     */
    cfg_template_t* runningcfg;
    runningcfg = cfg_get_config_id(NCX_CFGID_RUNNING);
    YUMA_ASSERT(!runningcfg || !runningcfg->root, return ERR_INTERNAL_VAL, "No running config available in u_microwave_model_init2!");

    /*
     * Creating the mw-pure-ethernet-structure-pac list and attach it to the running config
     */
    res = build_attributes_tree_and_attach_to_running_cfg(runningcfg);
    YUMA_ASSERT(res != NO_ERR, return ERR_INTERNAL_VAL, "Could not build the tree for the running config");

    return res;
} /* u_microwave_model_init2 */
