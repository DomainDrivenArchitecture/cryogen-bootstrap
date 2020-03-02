<div class="post-header">
	<h1>{{post.title}}</h1>
	<div class="row text-muted">
		{% if post.author %}
    		<div class="col text-left">
				Autor: {{post.author}}
			</div>
		{% endif %}
		<div class="col text-right">
			{{post.date|date:longDate}}
		</div>
	</div>
	{% if post.tags|not-empty %}
		<p class="text-muted"> 
			Tags: 
		    {% for tag in post.tags %}
		    	<a class="link-muted" href="{{tag.uri}}">{{tag.name}}</a>{% if not forloop.last %}, {% endif %}
		    {% endfor %}  
		</p>
	{% endif %}
</div>

<div>
    {% if post.toc %}{{post.toc|safe}}{% endif %}
    {{post.content|safe}}
</div>
