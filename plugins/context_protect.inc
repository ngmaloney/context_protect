<?php

/**
 * Displays closest matching menu based on context path.
 */
class context_protect extends context_reaction {
  function options_form($context) {
    $values = $this->fetch_from_context($context);
    $form = array();
    $form[] = array(
      '#type' => 'password',
      '#title' => t('Password'),
      '#default_value' => isset($values['password']) ? $values['password'] : '',
    );
    return $form;
  }

  function options_form_submit($values) {
    return $values;
  }

  function execute(&$vars) {
    $contexts = context_active_contexts();
    $execute = false;

    // Because magic_menus is set to run per path and not ALL contexts
    // we only need to check if it has been set to execute per request
    foreach($contexts as $active_context) {
      if(!empty($active_context->reactions['context_protect'])) {
        $password = $active_context->reactions['context_protect'];
        $execute = true;
        var_dump($password);
      }
    }
 }


}

