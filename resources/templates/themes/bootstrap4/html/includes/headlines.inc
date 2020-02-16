<!-- headlines.inc -->
<div class="row">
  {% for sub-page in page.children|filter-sidebar %}
   <div class="col-lg-4 text-center">
     <img class="rounded-circle" src="{{sub-page.headline-image}}" alt="{{sub-page.headline-image}}" width="140" height="140">
     <h2>{{sub-page.title}}</h2>
     <p>{{sub-page.abstract|safe}}</p>
     <p><a class="btn btn-secondary" 
     	{% if sub-page.action-uri %}href="{{sub-page.action-uri}}" target="_new"{% else %}href="{{sub-page.uri}}"{% endif %} 
     	role="button">{{sub-page.take-action|safe}}</a></p>
   </div>
  {% endfor %}
</div><!-- /.row -->