<div id="accordion" role="tablist" aria-multiselectable="true">
  {% for sub-page in page.children|filter-sidebar %}
  <div class="card">
    <div class="card-header" role="tab" id="accordionHeading{{forloop.counter0}}">
      <h5 class="mb-0">
        <a data-toggle="collapse" data-parent="#accordion" href="#accordionCollapse{{forloop.counter0}}" aria-expanded="true" aria-controls="collapseOne">
          {{sub-page.title}}
        </a>
      </h5>
    </div>

    <div id="accordionCollapse{{forloop.counter0}}" class="collapse" role="tabpanel" aria-labelledby="accordionHeading{{forloop.counter0}}">
      <div class="card-block">
        {{sub-page.abstract|safe}}
        {% if sub-page.take-action %}
         	<p><a class="btn btn-link" 
           		{% if sub-page.action-uri %}href="{{sub-page.action-uri}}" target="_new"{% else %}href="{{sub-page.uri}}"{% endif %}  
           		role="button">{{sub-page.take-action|safe}}
           	</a></p>
            {% endif %}
      </div>
    </div>
  </div>
  {% endfor %}
</div>