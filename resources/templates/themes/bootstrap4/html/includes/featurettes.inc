<!-- START THE FEATURETTES -->
{% for sub-page in page.children|filter-sidebar %}
	<hr class="featurette-divider">
	<div class="row featurette">
		
		{% if forloop.counter0|even? %}<div class="col-md-7">{% else %}<div class="col-md-7 push-md-5">{% endif %}
			<h2 class="featurette-heading">{{sub-page.title}}</h2>
			<p class="lead">{{sub-page.abstract|safe}}</p>
			<p><a class="btn btn-secondary" 
         			{% if sub-page.action-uri %}href="{{sub-page.action-uri}}" target="_new"{% else %}href="{{sub-page.uri}}"{% endif %} 
         			role="button">{{sub-page.take-action|safe}}</a></p>
			</div>
		{% if forloop.counter0|even? %}<div class="col-md-5">{% else %}<div class="col-md-5 pull-md-7">{% endif %}
			<img class="featurette-image img-fluid mx-auto" src="{{sub-page.featurette-image}}">
		</div>
	</div>
{% endfor %}