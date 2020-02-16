<div id="carousel" class="carousel slide carousel-adjust" data-ride="carousel">
  <ol class="carousel-indicators">
  	{% for sub-page in page.children|filter-sidebar %}
    	<li data-target="#carousel" data-slide-to="{{forloop.counter0}}" 
    		{% if forloop.first %}class="active"{% endif %}
    		>
    	</li>
  	{% endfor %}
  </ol>
  <div class="carousel-inner" role="listbox">
  	{% for sub-page in page.children|filter-sidebar %}
    	<div {% if forloop.first %}class="carousel-item active"{% else %}class="carousel-item"{% endif %}>
       <img class="d-block img-fluid" src="{{sub-page.carousel-image}}" alt="{{sub-page.carousel-image}}">
       <div class="carousel-caption d-none d-md-block text-left">
       	<h1>{{sub-page.title}}</h1>
         <p>{{sub-page.abstract|safe}}</p>
         <p><a class="btn btn-lg btn-primary" 
         	{% if sub-page.action-uri %}href="{{sub-page.action-uri}}"{% else %}href="{{sub-page.uri}}"{% endif %} 
	        role="button">{{sub-page.take-action|safe}}</a></p>
       </div>
     </div>
    {% endfor %}
  </div>
  <a class="carousel-control-prev" href="#carousel" role="button" data-slide="prev">
    <span class="carousel-control-prev-icon" aria-hidden="true"></span>
    <span class="sr-only">Previous</span>
  </a>
  <a class="carousel-control-next" href="#carousel" role="button" data-slide="next">
    <span class="carousel-control-next-icon" aria-hidden="true"></span>
    <span class="sr-only">Next</span>
  </a>
</div>
