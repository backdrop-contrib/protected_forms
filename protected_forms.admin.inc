<?php

/**
* Administrative settings form.
*/
function protected_forms_config() {
  $config = config('protected_forms.settings');

  $form = array();
  $form['#attached']['css'] = array(
    backdrop_get_path('module', 'protected_forms') . '/css/protected_forms.css',
  );

  $markup = '<p>' . t('The <em>Protected Forms</em> module tests each submission against several conditions starting from a simple honeypot to other ones that require gradually more calculations such as a minimum threshold, language script checks, preset patterns, and rejecting it as soon as it fails any of the checks.') . '</p>';
  $markup .= '<p>' . t('Make sure the <a href="@permissions">permissions</a> are set correctly for the <em>Protected Forms</em> to work as expected.', array('@permissions' => '/admin/config/people/permissions#module-protected_forms'))  . '</p>';
  $form['header'] = array(
    '#markup' => $markup,
  );
  $form['honeypot'] = array(
    '#type' => 'fieldset',
    '#title' => t('Step 1: Honeypot trap'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $honeypot_trap = $config->get('honeypot_trap');
  $form['honeypot']['honeypot_trap'] = array(
    '#type' => 'textfield',
    '#default_value' => $honeypot_trap,
    '#title' => t('Honeypot trap name'),
    '#required' => TRUE,
    '#description' => t('A honeypot field is an anti-spam technique that baits bots into filling out this hidden field. Human users cannot see the field so they don\'t fill it out. You can use any name for this field that makes sense such as <em>url, website, name, e-mail, city, country,</em> etc, or any other custom name taken from a professional jargon or terminology of your website\'s industry or specialty.'),
  );

  $post_size_threshold = $config->get('post_size_threshold');
  $form['post_size'] = array(
    '#type' => 'fieldset',
    '#title' => t('Step 2: Post-size check'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['post_size']['post_size_threshold'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 3,
    '#default_value' => $post_size_threshold,
    '#title' => t('Minimum post-size'),
    '#description' => t('Set a minimum threshold for number of characters in each post. Submissions containing less number of characters  than the set threshold are automatically rejected.'),
  );

  // Language settings.
  $allowed_scripts = $config->get('allowed_scripts');
  $allowed_scripts_keys = array_keys($allowed_scripts);
  sort($allowed_scripts_keys);
  $form['language'] = array(
    '#type' => 'fieldset',
    '#title' => t('Step 3: Language checks'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['language']['allowed_scripts'] = array(
    '#type' => 'checkboxes',
    '#options' => backdrop_map_assoc($allowed_scripts_keys),
    '#default_value' => $allowed_scripts,
    '#title' => t('Allowed language scripts'),
    '#required' => TRUE,
    '#description' => t('Select language scripts allowed for submission.'),
  );
  $form['language']['validate_percent'] = array(
    '#type' => 'textfield',
    '#default_value' => $config->get('validate_percent'),
    '#title' => t('Percentage to validate'),
    '#size' => 3,
    '#required' => TRUE,
    '#description' => t('Spam texts can be constructed using mixed characters from multiple languages. Validating each
    character would cause performance overhead, especially with large texts submitted. Therefore, start with 20% of
    randomly selected characters to check, and if characters of dissalowed languages start slipping in through the
    validation, then gradually increase it to the new optimum.'),
  );

  // Pattern settings.
  $allowed_patterns = $config->get('allowed_patterns');
  $reject_patterns = $config->get('reject_patterns');
  $form['patterns'] = array(
    '#type' => 'fieldset',
    '#title' => t('Step 4: Pattern checks'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['patterns']['allowed_patterns'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#columns' => 60,
    '#default_value' => strtolower($allowed_patterns),
    '#title' => t('Allowed patterns'),
    '#required' => FALSE,
    '#description' => t('Enter excluded words, patterns, professional jargon or terminology of your website\'s industry or specialty which should always pass the validation by separating them with commas or new lines.'),
  );
  $form['patterns']['reject_patterns'] = array(
    '#type' => 'textarea',
    '#rows' => 10,
    '#columns' => 60,
    '#default_value' => strtolower($reject_patterns),
    '#title' => t('Reject patterns'),
    '#required' => TRUE,
    '#description' => t('Enter patterns to reject by separating them with commas or new lines. The longer each pattern, the less likely legitimate submissions are blocked. For example, the reject pattern <strong><em>WIN</em></strong> would prevent submissions of any post that contains words like <strong><em>groWINg</em></strong>, <strong><em>WINdows</em></strong>, etc., unless they are excluded in the <strong>Allowed patterns</strong> section.'),
  );

  // Other settings.
  $form['reject_message'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#columns' => 60,
    '#default_value' => $config->get('reject_message'),
    '#title' => t('Reject message'),
    '#required' => TRUE,
    '#description' => t('Enter a message to display when submission of undesired pattern is attempted.'),
  );
  if (module_exists('dblog')) {
    $log_rejected = $config->get('log_rejected');
    $form['log_rejected'] = array(
      '#type' => 'checkbox',
      '#title' => t('Log rejected submissions?'),
      '#default_value' => $log_rejected,
      '#required' => FALSE,
      '#description' => t('Enable logging if you want to analyze rejected posts or start banning spammers based on their IP addresses.'),
    );
    if (module_exists('ip_blocking') && module_exists('dblog') && $log_rejected == TRUE) {
      $form['ban_threshold'] = array(
        '#type' => 'textfield',
        '#states' => array(
          // Only show this field when the 'log_rejected' checkbox is enabled.
          'visible' => array(
            ':input[name="log_rejected"]' => array('checked' => TRUE),
          ),
        ),
        '#size' => 3,
        '#default_value' => $config->get('ban_threshold'),
        '#title' => t('Threshold for banning'),
        '#required' => TRUE,
        '#description' => t('Set how many times an IP must be caught spamming before it gets <a href="@banned">banned from the site</a>.', array('@banned' => '/admin/config/people/ip-blocking')),
      );
    }
    else {
      $form['enable_ip_blocking'] = array(
        '#markup' => t('Additionally, if you enable the <a href="@ip">IP address blocking</a> module, then you can configure the automatic blocking of spam-originating IP addresses.', array('@ip' => 'https://backdropcms.org/project/ip_blocking')),
      );
    }
  }

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
* Validates protected_forms_config() and saves config values.
*/
function protected_forms_config_submit($form, &$form_state) {
  $config = config('protected_forms.settings');
  $config->set('allowed_scripts', $form_state['values']['allowed_scripts']);
  $config->set('allowed_patterns', $form_state['values']['allowed_patterns']);
  if ($form_state['values']['validate_percent'] > 100) {
    backdrop_set_message(t('You can not validate more than 100% of submitted texts. Also it\'s recomended to keep this value below 60% to avoid performance overhead.'), 'error');
    $form_state['values']['validate_percent'] = 100;
  }
  elseif ($form_state['values']['validate_percent'] < 5) {
    backdrop_set_message(t('We recommend to set at least 5% of submitted texts to validate.'), 'error');
    $form_state['values']['validate_percent'] = 5;
  }
  $config->set('validate_percent', $form_state['values']['validate_percent']);
  $config->set('reject_message', $form_state['values']['reject_message']);
  $config->set('reject_patterns', $form_state['values']['reject_patterns']);
  if (isset($form_state['values']['ban_threshold'])) {
    $config->set('ban_threshold', $form_state['values']['ban_threshold']);
  }
  if (isset($form_state['values']['log_rejected'])) {
    $config->set('log_rejected', $form_state['values']['log_rejected']);
  }
  if ($form_state['values']['post_size_threshold'] < 1) {
    backdrop_set_message(t('The minimum post-size threshold can not be less than 1 character.'), 'error');
    $config->set('post_size_threshold', '1');
  }
  else {
    $config->set('post_size_threshold', $form_state['values']['post_size_threshold']);
  }

  $config->set('honeypot_trap', $form_state['values']['honeypot_trap']);
  $config->save();
  backdrop_set_message(t('The configuration options have been saved.'));
}
