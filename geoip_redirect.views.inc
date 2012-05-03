<?php

/**
 * @file
 * Views 2 support for geoip_redirect.
 */

/**
 * Implementation of hook_views_handlers().
 */
function geoip_redirect_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'geoip_redirect'),
    ),
    'handlers' => array(
      'geoip_redirect_handler_field_countries' => array(
        'parent' => 'views_handler_field',
      ),
      'geoip_redirect_handler_filter_country' => array(
        'parent' => 'views_handler_filter',
      ),
      'geoip_redirect_handler_argument_country' => array(
        'parent' => 'views_handler_argument',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function geoip_redirect_views_data() {
  // ----------------------------------------------------------------
  // location table -- basic table information.

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.

  $data['geoip_redirect_node']['table']['group'] = t('GeoIP country');

  $data['geoip_redirect_node']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  // ----------------------------------------------------------------
  // location table -- fields

  // nid
  $data['geoip_redirect_node']['nid'] = array(
    'title' => t('nid'),
    'help' => t('The ID of the geoip_redirect node.'), // The help that appears on the UI,

  );

  $data['geoip_redirect_node']['code'] = array(
    'title' => t('country code'),
    'help' => t('The country code of the node.'),
    'argument' => array(
      'handler' => 'geoip_redirect_handler_argument_country',
      //'name field' => 'name',
    ),    
    'field' => array(
      'handler' => 'geoip_redirect_handler_field_countries', // @@@
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  // Tell the base tables about us.
  $data['node']['table']['join']['geoip_redirect'] = array(
    'left_table' => 'geoip_redirect_node',
    'left_field' => 'nid',
    'field' => 'nid',
  );

  return $data;
}


