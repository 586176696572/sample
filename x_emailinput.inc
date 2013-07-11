<?

/**
* Sample Code
*/

require_once ".x_textinput.inc";

/**
* Extends the x_textinput class
 * overrides the valid conditions to provide validation for it being an email 
 * address
 * provide the HTML5 html if requested, parent provides HTML4
*/

class x_emailinput extends x_textinput
{
    
    /**
     * overrides parent::validConsitions to validate that the input is an email
     * @param string $value the input to be validated
     * @return boolean
     */

    protected function validConditions($value)
    {
        $regex = '/^((\"[^\"\f\n\r\t\v\b]+\")|([\w\!\#\$\%\&\'\*\+\-\~\/\^\`\|\{\}]+' .
                '(\.[\w\!\#\$\%\&\'\*\+\-\~\/\^\`\|\{\}]+)*))@((\[(((25[0-5])|' .
                '(2[0-4][0-9])|([0-1]?[0-9]?[0-9]))\.((25[0-5])|(2[0-4][0-9])|' .
                '([0-1]?[0-9]?[0-9]))\.((25[0-5])|(2[0-4][0-9])|([0-1]?[0-9]?[0-9]))' .
                '\.((25[0-5])|(2[0-4][0-9])|([0-1]?[0-9]?[0-9])))\])|(((25[0-5])|' .
                '(2[0-4][0-9])|([0-1]?[0-9]?[0-9]))\.((25[0-5])|(2[0-4][0-9])|' .
                '([0-1]?[0-9]?[0-9]))\.((25[0-5])|(2[0-4][0-9])|([0-1]?[0-9]?[0-9]))' .
                '\.((25[0-5])|(2[0-4][0-9])|([0-1]?[0-9]?[0-9])))|' .
                '((([A-Za-z0-9\-])+\.)+[A-Za-z\-]+))$/';

        /**
         * Valid email address
         */
        if (preg_match($regex, $value))
        {
            return true;
        }

        /**
         * if it is not a required field, make sure it is null
         * it needs to be a valid email even if it isn't required.
         */
        if ($this->required == false && $value == null)
        {
            return true;
        }
        return false;
    }

    /**
     * if required return html5 else parent will handle it
     * @param string $type default display or hidden
     * @return string
     */
    
    protected function postHTML($type = "default")
    {
        if (X_HTML_5 == true)
        {
            $str = "<input type='email' maxlength='$this->maxlength' name='$this->postField'  id='" . $this->htmlID() . "' value='$this->value' " . $this->DOM['input'] . " " . $this->getRequiredHTML5() . " />";
        } else
        {
            $str = parent::postHTML($type);
        }
        return $str;
    }

}
?>