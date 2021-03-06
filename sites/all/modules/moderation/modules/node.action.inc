<?php

/**
 * Implementation of hook_moderation_action_info().
 */
function node_moderation_action_info() {
  $node_actions = array();
  $node_actions['node'] = array(
    'node_publish_action' => array(
      'event' => 'moderation_publish',
      'label data' => array(
        'data' => 'status',
        'labels' => array(
          0 => t('publish'),
          1 => t('unpublish'),
        ),
      ),
      'action' => array(
        'if' => array(
          'data' => array(
            'status',
            1,
          ),
          'do' => array(
            'status',
            0,
          ),
        ),
        'else if' => array(
          'data' => array(
            'status',
            0,
          ),
          'do' => array(
            'status',
            1,
          ),
        ),
      ),
    ),
    'node_promote_action' => array(
      'event' => 'moderation_promote',
      'label data' => array(
        'data' => 'promote',
        'labels' => array(
          0 => t('promote to frontpage'),
          1 => t('unpromote from frontpage'),
        ),
      ),
      'action' => array(
        'if' => array(
          'data' => array(
            'promote',
            1,
          ),
          'do' => array(
            'promote',
            0,
          ),
        ),
        'else if' => array(
          'data' => array(
            'promote',
            0,
          ),
          'do' => array(
            'promote',
            1,
          ),
        ),
      ),
    ),
    'node_make_sticky_action' => array(
      'event' => 'moderation_sticky',
      'label data' => array(
        'data' => 'sticky',
        'labels' => array(
          0 => t('make sticky'),
          1 => t('undo sticky'),
        ),
      ),
      'action' => array(
        'if' => array(
          'data' => array(
            'sticky',
            1,
          ),
          'do' => array(
            'sticky',
            0,
          ),
        ),
        'else if' => array(
          'data' => array(
            'sticky',
            0,
          ),
          'do' => array(
            'sticky',
            1,
          ),
        ),
      ),
    ),
  );
  return $node_actions;
}
