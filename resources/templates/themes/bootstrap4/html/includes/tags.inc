{% block tags %}
	{% if tags|not-empty %}
	<div id="tags">
	    <h3>Tags</h3>
	    <ul>
	        {% for tag in tags %}
	        <li><a href="{{tag.uri}}">{{tag.name}}</a></li>
	        {% endfor %}
	    </ul>
	</div>
	{% endif %}
{% endblock %}
